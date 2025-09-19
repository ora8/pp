#include <string.h>
#include "stdstring.h"

//
// String implementation
// Created with Copilot
//
void string_create(string *str, const char c_str[], size_t size)  
{
    if (size < sizeof(str->stack))
    {
        // Use stack storage
        memcpy(str->stack, c_str, size);
        str->stack[size] = '\0'; // Null-terminate
        str->heap.data = NULL;
        str->heap.size = size;
        str->heap.capacity = 0;
    }
    else
    {
        // Use heap storage
        str->heap.data = malloc(size + 1);
        if (!str->heap.data)
        {
            exit(EXIT_FAILURE);
        }
        memcpy(str->heap.data, c_str, size);
        str->heap.data[size] = '\0'; // Null-terminate
        str->heap.size = size;
        str->heap.capacity = size + 1;
    }
}
void string_destroy(string *str)
{
    if (str->heap.data)
    {
        free(str->heap.data);
        str->heap.data = NULL;
    }
    str->heap.size = 0;
    str->heap.capacity = 0;
}
void string_clear(string *str)
{
    if (str->heap.data)
    {
        str->heap.size = 0;
        if (str->heap.capacity > 0)
        {
            str->heap.data[0] = '\0'; // Null-terminate
        }
    }
    else
    {
        str->stack[0] = '\0'; // Null-terminate
        str->heap.size = 0;
    }
}
size_t string_size(const string *str)  
{
    return str->heap.data ? str->heap.size : strlen(str->stack);
}
size_t string_capacity(const string *str)   
{
    return str->heap.data ? str->heap.capacity : sizeof(str->stack);
}
const char *string_c_str(const string *str)
{
    return str->heap.data ? str->heap.data : str->stack;
}
void string_push_back(string *str, char c)
{
    size_t current_size = string_size(str);
    size_t current_capacity = string_capacity(str);

    if (current_size + 1 >= current_capacity)
    {
        // Need to resize
        size_t new_capacity = (current_capacity == 0) ? 1 : current_capacity * 2;
        string_reserve(str, new_capacity);
    }

    if (str->heap.data)
    {
        str->heap.data[current_size] = c;
        str->heap.data[current_size + 1] = '\0'; // Null-terminate
        str->heap.size++;
    }
    else
    {
        str->stack[current_size] = c;
        str->stack[current_size + 1] = '\0'; // Null-terminate
        str->heap.size++;
    }
}

void string_pop_back(string *str)   
{
    size_t current_size = string_size(str);
    if (current_size == 0)
    {
        return; // Nothing to pop
    }

    if (str->heap.data)
    {
        str->heap.size--;
        str->heap.data[str->heap.size] = '\0'; // Null-terminate
    }
    else
    {
        str->heap.size--;
        str->stack[str->heap.size] = '\0'; // Null-terminate
    }
}       
void string_reserve(string *str, size_t new_capacity)   
{
    if (new_capacity <= string_capacity(str))
    {
        return; // No need to reserve
    }

    if (str->heap.data)
    {
        char *new_data = realloc(str->heap.data, new_capacity);
        if (!new_data)
        {
            exit(EXIT_FAILURE);
        }
        str->heap.data = new_data;
        str->heap.capacity = new_capacity;
    }
    else
    {
        // Move from stack to heap
        char *new_data = malloc(new_capacity);
        if (!new_data)
        {
            exit(EXIT_FAILURE);
        }
        size_t current_size = string_size(str);
        memcpy(new_data, str->stack, current_size + 1); // +1 for null-terminator
        str->heap.data = new_data;
        str->heap.size = current_size;
        str->heap.capacity = new_capacity;
    }
}
void string_resize(string *str, size_t new_size)    
{
    size_t current_size = string_size(str);
    if (new_size < current_size)
    {
        // Shrink
        if (str->heap.data)
        {
            str->heap.size = new_size;
            str->heap.data[new_size] = '\0'; // Null-terminate
        }
        else
        {
            str->heap.size = new_size;
            str->stack[new_size] = '\0'; // Null-terminate
        }
    }
    else if (new_size > current_size)
    {
        // Expand
        if (new_size >= string_capacity(str))
        {
            string_reserve(str, new_size + 1); // +1 for null-terminator
        }

        if (str->heap.data)
        {
            memset(str->heap.data + current_size, '\0', new_size - current_size);
            str->heap.size = new_size;
            str->heap.data[new_size] = '\0'; // Null-terminate
        }
        else
        {
            memset(str->stack + current_size, '\0', new_size - current_size);
            str->heap.size = new_size;
            str->stack[new_size] = '\0'; // Null-terminate
        }
    }
}
int string_valid_index(const string *str, size_t index)
{
    return 0 <= index && index < string_size(str);
}
char string_get(const string *str, size_t index)    
{
    return str->heap.data ? str->heap.data[index] : str->stack[index];
}
void string_set(string *str, size_t index, char c)  
{
    if (str->heap.data)
    {
        str->heap.data[index] = c;
    }
    else
    {
        str->stack[index] = c;
    }
}
int string_find(const string *str, char c)    
{
    size_t size = string_size(str);
    const char *data = string_c_str(str);
    for (size_t i = 0; i < size; i++)
    {
        if (data[i] == c)
        {
            return (int)i;
        }
    }
    return -1; // Not found
}
void string_remove(string *str, size_t index)   
{
    size_t size = string_size(str);
    if (str->heap.data)
    {
        for (size_t i = index; i < size - 1; i++)
        {
            str->heap.data[i] = str->heap.data[i + 1];
        }
        str->heap.size--;
        str->heap.data[str->heap.size] = '\0'; // Null-terminate
    }
    else
    {
        for (size_t i = index; i < size - 1; i++)
        {
            str->stack[i] = str->stack[i + 1];
        }
        str->heap.size--;
        str->stack[str->heap.size] = '\0'; // Null-terminate
    }
}  
void string_insert(string *str, size_t index, char c)  
{
    size_t current_size = string_size(str);
    if (current_size + 1 >= string_capacity(str))
    {
        // Need to resize
        size_t new_capacity = (string_capacity(str) == 0) ? 1 : string_capacity(str) * 2;
        string_reserve(str, new_capacity);
    }

    if (str->heap.data)
    {
        for (size_t i = current_size; i > index; i--)
        {
            str->heap.data[i] = str->heap.data[i - 1];
        }
        str->heap.data[index] = c;
        str->heap.size++;
        str->heap.data[str->heap.size] = '\0'; // Null-terminate
    }
    else
    {
        for (size_t i = current_size; i > index; i--)
        {
            str->stack[i] = str->stack[i - 1];
        }
        str->stack[index] = c;
        str->heap.size++;
        str->stack[str->heap.size] = '\0'; // Null-terminate
    }
}   
void string_shrink_to_fit(string *str)  
{
    size_t current_size = string_size(str);
    if (str->heap.data && current_size < str->heap.capacity)
    {
        char *new_data = realloc(str->heap.data, current_size + 1); // +1 for null-terminator
        if (!new_data && current_size > 0)
        {
            exit(EXIT_FAILURE);
        }
        str->heap.data = new_data;
        str->heap.capacity = current_size + 1;
    }
}
void string_swap(string *str1, string *str2)
{
    string temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}   
void string_copy(const string *src, string *dest)   
{
    if (src->heap.data)
    {
        // Source is using heap
        if (dest->heap.data)
        {
            // Dest is also using heap
            if (dest->heap.capacity < src->heap.size + 1)
            {
                char *new_data = realloc(dest->heap.data, src->heap.size + 1);
                if (!new_data)
                {
                    exit(EXIT_FAILURE);
                }
                dest->heap.data = new_data;
                dest->heap.capacity = src->heap.size + 1;
            }
        }
        else
        {
            // Dest is using stack, move to heap
            dest->heap.data = malloc(src->heap.size + 1);
            if (!dest->heap.data)
            {
                exit(EXIT_FAILURE);
            }
            dest->heap.capacity = src->heap.size + 1;
        }
        memcpy(dest->heap.data, src->heap.data, src->heap.size + 1); // +1 for null-terminator
        dest->heap.size = src->heap.size;
    }
    else
    {
        // Source is using stack
        if (src->heap.size < sizeof(dest->stack))
        {
            // Can fit in dest's stack
            memcpy(dest->stack, src->stack, src->heap.size + 1); // +1 for null-terminator
            if (dest->heap.data)
            {
                free(dest->heap.data);
                dest->heap.data = NULL;
                dest->heap.capacity = 0;
            }
            dest->heap.size = src->heap.size;
        }
        else
        {
            // Need to use heap in dest
            if (dest->heap.data)
            {
                if (dest->heap.capacity < src->heap.size + 1)
                {
                    char *new_data = realloc(dest->heap.data, src->heap.size + 1);
                    if (!new_data)
                    {
                        exit(EXIT_FAILURE);
                    }
                    dest->heap.data = new_data;
                    dest->heap.capacity = src->heap.size + 1;
                }
            }
            else
            {
                dest->heap.data = malloc(src->heap.size + 1);
                if (!dest->heap.data)
                {
                    exit(EXIT_FAILURE);
                }
                dest->heap.capacity = src->heap.size + 1;
            }
            memcpy(dest->heap.data, src ->stack, src->heap.size + 1); // +1 for null-terminator
            dest->heap.size = src->heap.size;
        }
    }
}
void string_concat(string *dest, const string *src)  
{
    size_t dest_size = string_size(dest);
    size_t src_size = string_size(src);
    size_t new_size = dest_size + src_size;

    if (new_size >= string_capacity(dest))
    {
        string_reserve(dest, new_size + 1); // +1 for null-terminator
    }

    if (dest->heap.data)
    {
        memcpy(dest->heap.data + dest_size, string_c_str(src), src_size + 1); // +1 for null-terminator
        dest->heap.size = new_size;
    }
    else
    {
        memcpy(dest->stack + dest_size, string_c_str(src), src_size + 1); // +1 for null-terminator
        dest->heap.size = new_size;
    }
}       