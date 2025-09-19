#include <string.h>
#include <stdio.h>

#include "stdstring.h"

//
// String implementation
// Created with Copilot
//
static const size_t __stack_mask = 0x01;
static const size_t __heap_mask = 0x1ul;

static unsigned char stack_size(unsigned char masked_size)
{
    return masked_size >> 1;
}

static size_t heap_capacity(size_t capacity)
{
    return capacity & ~__heap_mask;
}

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
    str->heap.data = malloc(size + 1);
    if (!str->heap.data)
    {
        exit(EXIT_FAILURE);
    }
    memcpy(str->heap.data, c_str, size);
    str->heap.data[size] = '\0';
    str->heap.size = size;
    str->heap.capacity = (size + 1) | __heap_mask;
    str->stack.size |= __stack_mask; // Mark as heap
}

void string_finit(string *str)
{
    if ((str->stack.size & __stack_mask) == 0)
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
    if ((str->stack.size & __stack_mask) == 0)
    {
        str->stack.data[0] = '\0';
        str->stack.size = 0;
        return;
    }
    str->heap.data[0] = '\0';
    str->heap.size = 0;
}

size_t string_size(const string *str)

{
    if ((str->stack.size & __stack_mask) == 0)
    {
        return str->stack.size >> 1;
    }
    return str->heap.size;
}

const char *string_c_str(const string *str)
{
    if ((str->stack.size & __stack_mask) == 0)
    {
        return str->stack.data;
    }
    return str->heap.data;
}

void string_push_back(string *str, char c)
{
    size_t size;
    if ((str->stack.size & __stack_mask) == 0 && str->stack.size + 1 < sizeof(str->stack.data))
    {
        size = str->stack.size;
        str->stack.data[size] = c;
        str->stack.data[size + 1] = '\0';
        str->stack.size++;
        return;
    }

    size = str->heap.size;
    size_t capacity = str->heap.capacity & ~__heap_mask;
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
    if ((str->stack.size & __stack_mask) == 0)
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
    if ((str->stack.size & __stack_mask) == 0)
    {
        if (new_capacity < sizeof(str->stack.data))
        {
            // No need to move to heap, stack is enough
            return;
        }
        // Move from stack to heap
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
    size_t capacity = str->heap.capacity & ~__heap_mask;
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
    if ((str->stack.size & __stack_mask) == 0)
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
    if (new_size > (str->heap.capacity & ~__heap_mask) - 1)
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
    if ((str->stack.size & __stack_mask) == 0)
    {
        return str->stack.data[index];
    }
    return str->heap.data[index];
}

void string_set(string *str, size_t index, char c)
{
    if ((str->stack.size & __stack_mask) == 0)
    {
        str->stack.data[index] = c;
        return;
    }
    str->heap.data[index] = c;
}

int string_find(const string *str, char c)
{
    size_t size = string_size(str);
    if ((str->stack.size & __stack_mask) == 0)
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

    if ((str->stack.size & __stack_mask) == 0)
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

void string_insert(string *str, size_t index, char c)
{
    size_t size = string_size(str);

    if ((str->stack.size & __stack_mask) == 0)
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

void string_shrink_to_fit(string *str)
{
    if ((str->stack.size & __stack_mask) == 0)
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
    if ((src->stack.size & __stack_mask) == 0)
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

void string_concat(string *dest, const string *src)
{
    size_t dest_size = string_size(dest);
    size_t src_size = string_size(src);

    if (src_size == 0)
    {
        return;
    }

    // Ensure enough capacity
    if ((dest->stack.size & __stack_mask) == 0)
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