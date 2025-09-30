#include <string.h>
#include <stdio.h>

#include "stdarray.h"
#include "stdstring.h"

//
// string implementation
// Created with Copilot
//
static const unsigned char __stack_mask = 0x01;
static const size_t __heap_mask = 0x1ul;

string *string_create(const char c_str[])
{
    string *str = malloc(sizeof(string));
    if (!str)
    {
        exit(EXIT_FAILURE);
    }
    string_init(str, c_str);
    return str;
}

void string_init(string *str, const char c_str[])
{
    size_t size = strlen(c_str);
    if (size < ARRAY_SIZE(str->_stack._data))
    {
        CHAR_ARRAY_COPY(str->_stack._data, c_str, size);
        str->_stack._data[size] = '\0';
        str->_stack._size = size << __stack_mask;
        return;
    }
    size_t capacity = size % 2 == 0 ? size + 2 : size + 1;
    str->_heap._data = CHAR_ARRAY_CREATE(capacity);
    if (!str->_heap._data)
    {
        exit(EXIT_FAILURE);
    }
    CHAR_ARRAY_COPY(str->_heap._data, c_str, size);
    str->_heap._data[size] = '\0';
    str->_heap._size = size;
    str->_heap._capacity = capacity | __heap_mask;
    str->_stack._size |= __stack_mask; // Mark as _heap
}

static int string_stack_used(const string *str)
{
    return (str->_stack._size & __stack_mask) == 0;
}

void string_finit(string *str)
{
    if (string_stack_used(str))
    {
        str->_stack._data[0] = '\0';
        str->_stack._size = 0;
        return;
    }
    free(str->_heap._data);
    str->_heap._data = NULL;
    str->_heap._size = 0;
    str->_heap._capacity = 0;
}

void string_destroy(string *str)
{
    free(str);
}

void string_clear(string *str)
{
    if (string_stack_used(str))
    {
        str->_stack._data[0] = '\0';
        str->_stack._size = 0;
        return;
    }
    str->_heap._data[0] = '\0';
    str->_heap._size = 0;
}

int string_empty(const string *str)
{
    return string_size(str) == 0ul;
}

size_t string_size(const string *str)

{
    if (string_stack_used(str))
    {
        return (size_t)str->_stack._size >> 1;
    }
    return str->_heap._size;
}

const char *string_c_str(const string *str)
{
    if (string_stack_used(str))
    {
        return str->_stack._data;
    }
    return str->_heap._data;
}

static size_t string_heap_capacity(const string *str)
{
    return str->_heap._capacity & ~__heap_mask;
}

size_t string_capacity(const string *str)
{
    if (string_stack_used(str))
    {
        return ARRAY_SIZE(str->_stack._data);
    }
    return string_heap_capacity(str);
}

void string_push_back(string *str, char c)
{
    size_t size;
    if (string_stack_used(str) && str->_stack._size + 1 < ARRAY_SIZE(str->_stack._data))
    {
        size = str->_stack._size;
        str->_stack._data[size] = c;
        str->_stack._data[size + 1] = '\0';
        str->_stack._size++;
        return;
    }

    size = str->_heap._size;
    size_t _capacity = string_heap_capacity(str);
    if (size + 1 >= _capacity)
    {
        size_t new_capacity = (_capacity == 0) ? 2 : 2 * _capacity;
        string_reserve(str, new_capacity);
    }

    str->_heap._data[size] = c;
    str->_heap._data[size + 1] = '\0';
    str->_heap._size++;
}

char string_pop_back(string *str)
{
    char c;
    if (string_stack_used(str))
    {
        c = str->_stack._data[str->_stack._size - 1];
        str->_stack._data[str->_stack._size - 1] = '\0';
        str->_stack._size--;
        return c;
    }
    c = str->_heap._data[str->_heap._size - 1];
    str->_heap._data[str->_heap._size - 1] = '\0';
    str->_heap._size--;
    return c;
}

void string_reserve(string *str, size_t new_capacity)
{
    // If currently using _stack storage
    if (string_stack_used(str))
    {
        if (new_capacity < ARRAY_SIZE(str->_stack._data))
        {
            // No need to move to _heap, _stack is enough
            return;
        }
        // Move from _stack to _heap
        if (new_capacity % 2)
        {
            new_capacity++;
        }
        char *new_property = CHAR_ARRAY_CREATE(new_capacity);
        if (!new_property)
        {
            exit(EXIT_FAILURE);
        }
        CHAR_ARRAY_COPY(new_property, str->_stack._data, str->_stack._size + 1);
        str->_heap._data = new_property;
        str->_heap._size = str->_stack._size;
        str->_heap._capacity = new_capacity | __heap_mask;
        str->_stack._size |= __stack_mask; // Mark as _heap
        return;
    }

    // Already using _heap storage
    size_t _capacity = string_heap_capacity(str);
    if (new_capacity % 2)
    {
        new_capacity++;
    }
    if (new_capacity <= _capacity)
    {
        // Already enough _capacity
        return;
    }
    char *new_property = CHAR_ARRAY_RECREATE(str->_heap._data, new_capacity);
    if (!new_property)
    {
        exit(EXIT_FAILURE);
    }
    str->_heap._data = new_property;
    str->_heap._capacity = new_capacity | __heap_mask;
}

void string_resize(string *str, size_t new_size)
{
    if (string_stack_used(str))
    {
        // Currently using _stack
        if (new_size < ARRAY_SIZE(str->_stack._data))
        {
            // Just resize within _stack
            if (new_size < str->_stack._size)
            {
                str->_stack._data[new_size] = '\0';
            }
            // Zero-fill new bytes if growing
            else
            {
                CHAR_ARRAY_ZERO(str->_stack._data + str->_stack._size, new_size - str->_stack._size);
                str->_stack._data[new_size] = '\0';
            }
            str->_stack._size = new_size;
            return;
        }
        // Need to move to _heap
        string_reserve(str, new_size + 1);
        CHAR_ARRAY_ZERO(str->_heap._data + str->_stack._size, new_size - str->_stack._size);
        str->_heap._data[new_size] = '\0';
        str->_heap._size = new_size;
        str->_stack._size |= __stack_mask; // Mark as _heap
        return;
    }
    // Already using _heap
    if (new_size > string_heap_capacity(str) - 1)
    {
        string_reserve(str, new_size + 1);
    }
    if (new_size > str->_heap._size)
    {
        CHAR_ARRAY_ZERO(str->_heap._data + str->_heap._size, new_size - str->_heap._size);
    }
    str->_heap._data[new_size] = '\0';
    str->_heap._size = new_size;
}

int string_valid_index(const string *str, size_t index)
{
    size_t _size = string_size(str);
    return index < _size;
}

char string_get(const string *str, size_t index)
{
    if (string_stack_used(str))
    {
        return str->_stack._data[index];
    }
    return str->_heap._data[index];
}

void string_set(string *str, size_t index, char c)
{
    if (string_stack_used(str))
    {
        str->_stack._data[index] = c;
        return;
    }
    str->_heap._data[index] = c;
}

int string_find(const string *str, char c)
{
    size_t _size = string_size(str);
    if (string_stack_used(str))
    {
        for (size_t i = 0; i < _size; ++i)
        {
            if (str->_stack._data[i] == c)
                return (int)i;
        }
    }
    else
    {
        for (size_t i = 0; i < _size; ++i)
        {
            if (str->_heap._data[i] == c)
                return (int)i;
        }
    }
    return -1;
}

void string_remove(string *str, size_t index)
{
    size_t _size = string_size(str);

    if (string_stack_used(str))
    {
        // _stack storage
        for (size_t i = index; i < _size - 1; ++i)
        {
            str->_stack._data[i] = str->_stack._data[i + 1];
        }
        str->_stack._data[_size - 1] = '\0';
        str->_stack._size--;
    }
    else
    {
        // _heap storage
        for (size_t i = index; i < str->_heap._size - 1; ++i)
        {
            str->_heap._data[i] = str->_heap._data[i + 1];
        }
        str->_heap._data[str->_heap._size - 1] = '\0';
        str->_heap._size--;
    }
}

void string_insert_char(string *str, size_t index, char c)
{
    size_t size = string_size(str);

    if (string_stack_used(str))
    {
        // _stack storage
        if (size + 1 < ARRAY_SIZE(str->_stack._data))
        {
            // Shift right to make space
            for (size_t i = size; i > index; --i)
            {
                str->_stack._data[i] = str->_stack._data[i - 1];
            }
            str->_stack._data[index] = c;
            str->_stack._size++;
            str->_stack._data[str->_stack._size] = '\0';
            return;
        }
        // Need to move to _heap
        string_reserve(str, size + 2);
        // Copy _stack to _heap
        CHAR_ARRAY_OVERLAP_COPY(str->_heap._data, str->_stack._data, index);
        str->_heap._data[index] = c;
        CHAR_ARRAY_OVERLAP_COPY(str->_heap._data + index + 1, str->_stack._data + index, size - index + 1); // +1 for null
        str->_heap._size = size + 1;
        str->_stack._size |= __stack_mask; // Mark as _heap
        return;
    }
    // _heap storage
    if (size + 1 >= (str->_heap._capacity & ~__heap_mask))
    {
        string_reserve(str, size + 2);
    }
    CHAR_ARRAY_OVERLAP_COPY(str->_heap._data + index + 1, str->_heap._data + index, size - index + 1); // +1 for null
    str->_heap._data[index] = c;
    str->_heap._size++;
}

static void string_insert_str_ex(string *str, size_t index, const char *s, size_t ssize)
{
    size_t size = string_size(str);
    if (string_stack_used(str))
    {
        // _stack storage
        if (size + ssize < sizeof(str->_stack._data))
        {
            // Shift right to make space
            CHAR_ARRAY_OVERLAP_COPY(str->_stack._data + index + ssize, str->_stack._data + index, size - index + 1); // +1 for null
            CHAR_ARRAY_OVERLAP_COPY(str->_stack._data + index, s, ssize);
            size_t new_size = (str->_stack._size >> 1) + ssize;
            str->_stack._size = (new_size + ssize) << 1;
            return;
        }
        // Need to move to _heap
        string_reserve(str, size + ssize);
        // Copy _stack to _heap
        CHAR_ARRAY_COPY(str->_heap._data, str->_stack._data, index);
        CHAR_ARRAY_COPY(str->_heap._data + index, s, ssize);
        CHAR_ARRAY_COPY(str->_heap._data + index + ssize, str->_stack._data + index, size - index + 1); // +1 for null
        str->_heap._size = size + ssize;
        str->_stack._size |= __stack_mask; // Mark as _heap
        return;
    }
    // _heap storage
    if (size + ssize >= (str->_heap._capacity & ~__heap_mask))
    {
        string_reserve(str, ssize);
    }
    CHAR_ARRAY_OVERLAP_COPY(str->_heap._data + index + ssize, str->_heap._data + index, size - index + 1); // +1 for null
    CHAR_ARRAY_COPY(str->_heap._data + index, s, ssize);
    str->_heap._size = size + ssize;
}

void string_insert_str(string *str, size_t index, const char s[])
{
    string_insert_str_ex(str, index, s, strlen(s));
}

void string_insert_string(string *str, size_t index, const string *str2)
{
    string_insert_str_ex(str, index, string_c_str(str2), string_size(str2));
}

void string_shrink_to_fit(string *str)
{
    if (string_stack_used(str))
    {
        // _stack storage, nothing to shrink
        return;
    }
    size_t size = str->_heap._size;
    size_t capacity = size % 2 ? size + 1 : size + 2;
    char *new_data = CHAR_ARRAY_RECREATE(str->_heap._data, capacity);
    if (!new_data && capacity > 0)
    {
        exit(EXIT_FAILURE);
    }
    str->_heap._data = new_data;
    str->_heap._capacity = capacity | __heap_mask;
}

void string_swap(string *str1, string *str2)
{
    string temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

void string_clone(string *dest, const string *src)
{
    size_t src_size = string_size(src);
    if (string_stack_used(src))
    {
        // Source is _stack
        if (src_size < sizeof(dest->_stack._data))
        {
            CHAR_ARRAY_COPY(dest->_stack._data, src->_stack._data, src_size + 1); // +1 for null terminator
            dest->_stack._size = src_size;
            return;
        }
        // Need to move dest to _heap
        string_reserve(dest, src_size + 1);
        CHAR_ARRAY_COPY(dest->_heap._data, src->_stack._data, src_size + 1);
        dest->_heap._size = src_size;
        dest->_stack._size |= __stack_mask; // Mark as _heap
        return;
    }
    else
    {
        // Source is _heap
        string_reserve(dest, src_size + 1);
        CHAR_ARRAY_COPY(dest->_heap._data, src->_heap._data, src_size + 1);
        dest->_heap._size = src_size;
        dest->_stack._size |= __stack_mask; // Mark as _heap
        return;
    }
}

void string_move(string *dest, string *src)
{
    if (!string_stack_used(dest))
    {
        free(dest->_heap._data);
    }
    if (string_stack_used(src))
    {
        unsigned char size = src->_stack._size;
        CHAR_ARRAY_COPY(dest->_stack._data, src->_stack._data, size + 1);
        dest->_stack._size = size;
    }
    else
    {
        size_t size = src->_heap._size;
        string_reserve(dest, size);
        CHAR_ARRAY_COPY(dest->_heap._data, src->_heap._data, size + 1);
        dest->_heap._size = size;
    }
}

void string_concat(string *dest, const string *src)
{
    size_t dest_size = string_size(dest);
    size_t src_size = string_size(src);

    if (src_size == 0)
    {
        return;
    }

    // Ensure enough _capacity
    if (string_stack_used(dest))
    {
        // dest is _stack
        if (dest_size + src_size < ARRAY_SIZE(dest->_stack._data))
        {
            CHAR_ARRAY_COPY(dest->_stack._data + dest_size, string_c_str(src), src_size + 1); // +1 for null
            dest->_stack._size += src_size;
            return;
        }
        // Need to move to _heap
        string_reserve(dest, dest_size + src_size + 1);
        CHAR_ARRAY_COPY(dest->_heap._data + dest_size, string_c_str(src), src_size + 1);
        dest->_heap._size = dest_size + src_size;
        dest->_stack._size |= __stack_mask; // Mark as _heap
        return;
    }
    // dest is _heap
    if (dest_size + src_size + 1 > (dest->_heap._capacity & ~__heap_mask))
    {
        string_reserve(dest, dest_size + src_size + 1);
    }
    CHAR_ARRAY_COPY(dest->_heap._data + dest_size, string_c_str(src), src_size + 1);
    dest->_heap._size = dest_size + src_size;
}