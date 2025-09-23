#include <string.h>
#include <stdio.h>

#include "stdstring.h"

//
// String implementation
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
    if (size < sizeof(str->stack.data))
    {
        memcpy(str->stack.data, c_str, size);
        str->stack.data[size] = '\0';
        str->stack.size = size << __stack_mask;
        return;
    }
    size_t capacity = size % 2 == 0 ? size + 2 : size + 1;
    str->heap.data = malloc(capacity);
    if (!str->heap.data)
    {
        exit(EXIT_FAILURE);
    }
    memcpy(str->heap.data, c_str, size);
    str->heap.data[size] = '\0';
    str->heap.size = size;
    str->heap.capacity = capacity | __heap_mask;
    str->stack.size |= __stack_mask; // Mark as heap
}

static int string_stack_used(const string *str)
{
    return (str->stack.size & __stack_mask) == 0;
}

void string_finit(string *str)
{
    if (string_stack_used(str))
    {
        str->stack.data[0] = '\0';
        str->stack.size = 0;
        return;
    }
    free(str->heap.data);
    str->heap.data = NULL;
    str->heap.size = 0;
    str->heap.capacity = 0;
}

void string_destroy(string *str)
{
    free(str);
}

void string_clear(string *str)
{
    if (string_stack_used(str))
    {
        str->stack.data[0] = '\0';
        str->stack.size = 0;
        return;
    }
    str->heap.data[0] = '\0';
    str->heap.size = 0;
}

int string_empty(const string *str)
{
    return string_size(str) == 0ul;
}

size_t string_size(const string *str)

{
    if (string_stack_used(str))
    {
        return (size_t)str->stack.size >> 1;
    }
    return str->heap.size;
}

const char *string_c_str(const string *str)
{
    if (string_stack_used(str))
    {
        return str->stack.data;
    }
    return str->heap.data;
}

static size_t string_heap_capacity(const string *str)
{
    return str->heap.capacity & ~__heap_mask;
}

size_t string_capacity(const string *str)
{
    if (string_stack_used(str))
    {
        return sizeof(str->stack.data);
    }
    //
    return string_heap_capacity(str);
}

void string_push_back(string *str, char c)
{
    size_t size;
    if (string_stack_used(str) && str->stack.size + 1 < sizeof(str->stack.data))
    {
        size = str->stack.size;
        str->stack.data[size] = c;
        str->stack.data[size + 1] = '\0';
        str->stack.size++;
        return;
    }

    size = str->heap.size;
    size_t capacity = string_heap_capacity(str);
    if (size + 1 >= capacity)
    {
        size_t new_capacity = (capacity == 0) ? 2 : 2 * capacity;
        string_reserve(str, new_capacity);
    }

    str->heap.data[size] = c;
    str->heap.data[size + 1] = '\0';
    str->heap.size++;
}

char string_pop_back(string *str)
{
    char c;
    if (string_stack_used(str))
    {
        c = str->stack.data[str->stack.size - 1];
        str->stack.data[str->stack.size - 1] = '\0';
        str->stack.size--;
        return c;
    }
    c = str->heap.data[str->heap.size - 1];
    str->heap.data[str->heap.size - 1] = '\0';
    str->heap.size--;
    return c;
}

void string_reserve(string *str, size_t new_capacity)
{
    // If currently using stack storage
    if (string_stack_used(str))
    {
        if (new_capacity < sizeof(str->stack.data))
        {
            // No need to move to heap, stack is enough
            return;
        }
        // Move from stack to heap
        if (new_capacity % 2 == 0)
        {
            new_capacity++;
        }
        char *new_data = malloc(new_capacity);
        if (!new_data)
        {
            exit(EXIT_FAILURE);
        }
        memcpy(new_data, str->stack.data, str->stack.size + 1); // +1 for null terminator
        str->heap.data = new_data;
        str->heap.size = str->stack.size;
        str->heap.capacity = new_capacity | __heap_mask;
        str->stack.size |= __stack_mask; // Mark as heap
        return;
    }

    // Already using heap storage
    size_t capacity = string_heap_capacity(str);
    if (new_capacity % 2 == 0)
    {
        new_capacity++;
    }
    if (new_capacity <= capacity)
    {
        // Already enough capacity
        return;
    }
    char *new_data = realloc(str->heap.data, new_capacity);
    if (!new_data)
    {
        exit(EXIT_FAILURE);
    }
    str->heap.data = new_data;
    str->heap.capacity = new_capacity | __heap_mask;
}

void string_resize(string *str, size_t new_size)
{
    if (string_stack_used(str))
    {
        // Currently using stack
        if (new_size < sizeof(str->stack.data))
        {
            // Just resize within stack
            if (new_size < str->stack.size)
            {
                str->stack.data[new_size] = '\0';
            }
            // Zero-fill new bytes if growing
            else
            {
                memset(str->stack.data + str->stack.size, 0, new_size - str->stack.size);
                str->stack.data[new_size] = '\0';
            }
            str->stack.size = new_size;
            return;
        }
        // Need to move to heap
        string_reserve(str, new_size + 1);
        memset(str->heap.data + str->stack.size, 0, new_size - str->stack.size);
        str->heap.data[new_size] = '\0';
        str->heap.size = new_size;
        str->stack.size |= __stack_mask; // Mark as heap
        return;
    }
    // Already using heap
    if (new_size > string_heap_capacity(str) - 1)
    {
        string_reserve(str, new_size + 1);
    }
    if (new_size > str->heap.size)
    {
        memset(str->heap.data + str->heap.size, 0, new_size - str->heap.size);
    }
    str->heap.data[new_size] = '\0';
    str->heap.size = new_size;
}

int string_valid_index(const string *str, size_t index)
{
    size_t size = string_size(str);
    return index < size;
}

char string_get(const string *str, size_t index)
{
    if (string_stack_used(str))
    {
        return str->stack.data[index];
    }
    return str->heap.data[index];
}

void string_set(string *str, size_t index, char c)
{
    if (string_stack_used(str))
    {
        str->stack.data[index] = c;
        return;
    }
    str->heap.data[index] = c;
}

int string_find(const string *str, char c)
{
    size_t size = string_size(str);
    if (string_stack_used(str))
    {
        for (size_t i = 0; i < size; ++i)
        {
            if (str->stack.data[i] == c)
                return (int)i;
        }
    }
    else
    {
        for (size_t i = 0; i < size; ++i)
        {
            if (str->heap.data[i] == c)
                return (int)i;
        }
    }
    return -1;
}

void string_remove(string *str, size_t index)
{
    size_t size = string_size(str);

    if (string_stack_used(str))
    {
        // Stack storage
        for (size_t i = index; i < size - 1; ++i)
        {
            str->stack.data[i] = str->stack.data[i + 1];
        }
        str->stack.data[size - 1] = '\0';
        str->stack.size--;
    }
    else
    {
        // Heap storage
        for (size_t i = index; i < str->heap.size - 1; ++i)
        {
            str->heap.data[i] = str->heap.data[i + 1];
        }
        str->heap.data[str->heap.size - 1] = '\0';
        str->heap.size--;
    }
}

void string_insert_char(string *str, size_t index, char c)
{
    size_t size = string_size(str);

    if (string_stack_used(str))
    {
        // Stack storage
        if (size + 1 < sizeof(str->stack.data))
        {
            // Shift right to make space
            for (size_t i = size; i > index; --i)
            {
                str->stack.data[i] = str->stack.data[i - 1];
            }
            str->stack.data[index] = c;
            str->stack.size++;
            str->stack.data[str->stack.size] = '\0';
            return;
        }
        // Need to move to heap
        string_reserve(str, size + 2);
        // Copy stack to heap
        memmove(str->heap.data, str->stack.data, index);
        str->heap.data[index] = c;
        memmove(str->heap.data + index + 1, str->stack.data + index, size - index + 1); // +1 for null
        str->heap.size = size + 1;
        str->stack.size |= __stack_mask; // Mark as heap
        return;
    }
    // Heap storage
    if (size + 1 >= (str->heap.capacity & ~__heap_mask))
    {
        string_reserve(str, size + 2);
    }
    memmove(str->heap.data + index + 1, str->heap.data + index, size - index + 1); // +1 for null
    str->heap.data[index] = c;
    str->heap.size++;
}

static void string_insert_str_ex(string *str, size_t index, const char *s, size_t ssize)
{
    size_t size = string_size(str);
    if (string_stack_used(str))
    {
        // Stack storage
        if (size + ssize < sizeof(str->stack.data))
        {
            // Shift right to make space
            memmove(str->stack.data + index + ssize, str->stack.data + index, size - index + 1); // +1 for null
            memmove(str->stack.data + index, s, ssize);
            size_t new_size = (str->stack.size >> 1) + ssize;
            str->stack.size = (new_size + ssize) << 1;
            return;
        }
        // Need to move to heap
        string_reserve(str, size + ssize);
        // Copy stack to heap
        memmove(str->heap.data, str->stack.data, index);
        memmove(str->heap.data + index, s, ssize);
        memmove(str->heap.data + index + ssize, str->stack.data + index, size - index + 1); // +1 for null
        str->heap.size = size + ssize;
        str->stack.size |= __stack_mask; // Mark as heap
        return;
    }
    // Heap storage
    if (size + ssize >= (str->heap.capacity & ~__heap_mask))
    {
        string_reserve(str, ssize);
    }
    memmove(str->heap.data + index + ssize, str->heap.data + index, size - index + 1); // +1 for null
    memmove(str->heap.data + index, s, ssize);
    str->heap.size = size + ssize;
}

void string_insert_str(string *str, size_t index, const char *s)
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
        // Stack storage, nothing to shrink
        return;
    }
    size_t size = str->heap.size;
    if (size + 1 < (str->heap.capacity & ~__heap_mask))
    {
        char *new_data = realloc(str->heap.data, size + 1);
        if (!new_data && size > 0)
        {
            exit(EXIT_FAILURE);
        }
        str->heap.data = new_data;
        str->heap.capacity = (size + 1) | __heap_mask;
    }
}

void string_swap(string *str1, string *str2)
{
    string temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

void string_copy(string *dest, const string *src)
{
    size_t src_size = string_size(src);
    if (string_stack_used(src))
    {
        // Source is stack
        if (src_size < sizeof(dest->stack.data))
        {
            memcpy(dest->stack.data, src->stack.data, src_size + 1); // +1 for null terminator
            dest->stack.size = src_size;
            return;
        }
        // Need to move dest to heap
        string_reserve(dest, src_size + 1);
        memcpy(dest->heap.data, src->stack.data, src_size + 1);
        dest->heap.size = src_size;
        dest->stack.size |= __stack_mask; // Mark as heap
        return;
    }
    else
    {
        // Source is heap
        string_reserve(dest, src_size + 1);
        memcpy(dest->heap.data, src->heap.data, src_size + 1);
        dest->heap.size = src_size;
        dest->stack.size |= __stack_mask; // Mark as heap
        return;
    }
}

void string_move(string *dest, string *src)
{
    if (!string_stack_used(dest)) {
        free(dest->heap.data);
    }
    if (string_stack_used(src)) {
        unsigned char size = src->stack.size;
        memcpy(dest->stack.data, src->stack.data, size + 1);
        dest->stack.size = size;
    }
    else {
        size_t size = src->heap.size;
        string_reserve(dest, size);
        memcpy(dest->heap.data, src->heap.data, size + 1);
        dest->heap.size = size;
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

    // Ensure enough capacity
    if (string_stack_used(dest))
    {
        // dest is stack
        if (dest_size + src_size < sizeof(dest->stack.data))
        {
            memcpy(dest->stack.data + dest_size, string_c_str(src), src_size + 1); // +1 for null
            dest->stack.size += src_size;
            return;
        }
        // Need to move to heap
        string_reserve(dest, dest_size + src_size + 1);
        memcpy(dest->heap.data + dest_size, string_c_str(src), src_size + 1);
        dest->heap.size = dest_size + src_size;
        dest->stack.size |= __stack_mask; // Mark as heap
        return;
    }
    // dest is heap
    if (dest_size + src_size + 1 > (dest->heap.capacity & ~__heap_mask))
    {
        string_reserve(dest, dest_size + src_size + 1);
    }
    memcpy(dest->heap.data + dest_size, string_c_str(src), src_size + 1);
    dest->heap.size = dest_size + src_size;
}