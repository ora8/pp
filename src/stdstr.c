#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stdstr.h"

//
// Small string function implementations
//
small_str *small_str_create(const char *s)
{
    STR_CREATE(small_str, s);
}

void small_str_init(small_str *str, const char *s)
{
    STR_INIT(str, s);
}

void small_str_destroy(small_str *str)
{
    STR_DESTROY(str);
}

// Function to clear the contents of a small_str
void small_str_clear(small_str *str)
{
    STR_CLEAR(str);
}

// Function to get the size of a small_str
unsigned char small_str_size(const small_str *str)
{
    STR_SIZE(str);
}

// Function to get a C string from a small_str
const char *small_str_c_str(const small_str *str)
{
    STR_C_STR(str);
}

// Function to push a character to the back of a small_str
void small_str_push_back(small_str *str, char c)
{
    STR_PUSH_BACK(str, c);
}

// Function to pop a character from the back of a small_str
char small_str_pop_back(small_str *str)
{
    STR_POP_BACK(str);
}

// Function to resize a small_str
int small_str_resize(small_str *str, unsigned char new_size)
{
    STR_RESIZE(str, new_size);
}

// Function to check if an index is valid
int small_str_valid_index(const small_str *str, unsigned char index)
{
    STR_VALID_INDEX(str, index);
}

// Function to get a character at a specific index
char small_str_get(const small_str *str, unsigned char index)
{
    STR_GET(str, index);
}

// Function to set a character at a specific index
void small_str_set(small_str *str, unsigned index, char c)
{
    STR_SET(str, index, c);
}

// Function to find a character in a small_str
int small_str_find(const small_str *str, char c)
{
    STR_FIND(str, c);
}

// Function to remove a character at a specific index
void small_str_remove(small_str *str, unsigned char index)
{
    STR_REMOVE(str, index);
}

// Function to insert a character at a specific index
void small_str_insert(small_str *str, unsigned char index, char c)
{
    STR_INSERT(str, index, c);
}

// Function to swap two small_str objects
void small_str_swap(small_str *str1, small_str *str2)
{
    STR_SWAP(small_str, str1, str2);
}

// Function to copy one small_str to another
void small_str_copy(small_str *dest, const small_str *src)
{
    STR_COPY(dest, src);
}

// Function to concatenate two small_str objects
void small_str_concat(small_str *dest, const small_str *src)
{
    STR_CONCAT(dest, src);
}

//
// Medium string function implementations
//
medium_str *medium_str_create(const char *s)
{
    STR_CREATE(medium_str, s);
}

void medium_str_init(medium_str *str, const char *s)
{
    STR_INIT(str, s);
}

void medium_str_destroy(medium_str *str)
{
    STR_DESTROY(str);
}

// Function to clear the contents of a medium_str
void medium_str_clear(medium_str *str)
{
    STR_CLEAR(str);
}

// Function to get the size of a medium_str
unsigned char medium_str_size(const medium_str *str)
{
    STR_SIZE(str);
}

// Function to get a C string from a medium_str
const char *medium_str_c_str(const medium_str *str)
{
    STR_C_STR(str);
}

// Function to push a character to the back of a medium_str
void medium_str_push_back(medium_str *str, char c)
{
    STR_PUSH_BACK(str, c);
}

// Function to pop a character from the back of a medium_str
char medium_str_pop_back(medium_str *str)
{
    STR_POP_BACK(str);
}

// Function to resize a medium_str
int medium_str_resize(medium_str *str, unsigned char new_size)
{
    STR_RESIZE(str, new_size);
}

// Function to check if an index is valid
int medium_str_valid_index(const medium_str *str, unsigned char index)
{
    STR_VALID_INDEX(str, index);
}

// Function to get a character at a specific index
char medium_str_get(const medium_str *str, unsigned char index)
{
    STR_GET(str, index);
}

// Function to set a character at a specific index
void medium_str_set(medium_str *str, unsigned index, char c)
{
    STR_SET(str, index, c);
}

// Function to find a character in a medium_str
int medium_str_find(const medium_str *str, char c)
{
    STR_FIND(str, c);
}

// Function to remove a character at a specific index
void medium_str_remove(medium_str *str, unsigned char index)
{
    STR_REMOVE(str, index);
}

// Function to insert a character at a specific index
void medium_str_insert(medium_str *str, unsigned char index, char c)
{
    STR_INSERT(str, index, c);
}

// Function to swap two medium_str objects
void medium_str_swap(medium_str *str1, medium_str *str2)
{
    STR_SWAP(medium_str, str1, str2);
}

// Function to copy one medium_str to another
void medium_str_copy(medium_str *dest, const medium_str *src)
{
    STR_COPY(dest, src);
}

// Function to concatenate two medium_str objects
void medium_str_concat(medium_str *dest, const medium_str *src)
{
    STR_CONCAT(dest, src);
}

//
// String function implementations
//
str *str_create(const char *s)
{
    STR_CREATE(str, s);
}

void str_init(str *str, const char *s)
{
    STR_INIT(str, s);
}

void str_destroy(str *str)
{
    STR_DESTROY(str);
}

// Function to clear the contents of a str
void str_clear(str *str)
{
    STR_CLEAR(str);
}

// Function to get the size of a str
unsigned char str_size(const str *str)
{
    STR_SIZE(str);
}

// Function to get a C string from a str
const char *str_c_str(const str *str)
{
    STR_C_STR(str);
}

// Function to push a character to the back of a str
void str_push_back(str *str, char c)
{
    STR_PUSH_BACK(str, c);
}

// Function to pop a character from the back of a str
char str_pop_back(str *str)
{
    STR_POP_BACK(str);
}

// Function to resize a str
int str_resize(str *str, unsigned char new_size)
{
    STR_RESIZE(str, new_size);
}

// Function to check if an index is valid
int str_valid_index(const str *str, unsigned char index)
{
    STR_VALID_INDEX(str, index);
}

// Function to get a character at a specific index
char str_get(const str *str, unsigned char index)
{
    STR_GET(str, index);
}

// Function to set a character at a specific index
void str_set(str *str, unsigned index, char c)
{
    STR_SET(str, index, c);
}

// Function to find a character in a str
int str_find(const str *str, char c)
{
    STR_FIND(str, c);
}

// Function to remove a character at a specific index
void str_remove(str *str, unsigned char index)
{
    STR_REMOVE(str, index);
}

// Function to insert a character at a specific index
void str_insert(str *str, unsigned char index, char c)
{
    STR_INSERT(str, index, c);
}

// Function to swap two str objects
void str_swap(str *str1, str *str2)
{
    STR_SWAP(str, str1, str2);
}

// Function to copy one str to another
void str_copy(str *dest, const str *src)
{
    STR_COPY(dest, src);
}

// Function to concatenate two str objects
void str_concat(str *dest, const str *src)
{
    STR_CONCAT(dest, src);
}

//
// Dynamic string
//

// Function to create a new dynamic string
dyn_str *dyn_str_create(const char *s)
{
    dyn_str *new_str = (dyn_str *)malloc(sizeof(dyn_str));
    if (!new_str)
    {
        exit(EXIT_FAILURE);
    }
    dyn_str_init(new_str, s);
    return new_str;
}

// Function to initialize a dynamic string
void dyn_str_init(dyn_str *d_str, const char *s)
{
    d_str->size = strlen(s);
    d_str->capacity = d_str->size + 1; // +1 for the null terminator
    d_str->data = (char *)malloc(d_str->capacity * sizeof(char));
    if (!d_str->data)
    {
        exit(EXIT_FAILURE);
    }
    strcpy(d_str->data, s);
}

// Function to destroy the dynamic string
void dyn_str_destroy(dyn_str *d_str)
{
    free(d_str->data);
    free(d_str);
}

// Function to clear the dynamic string
void dyn_str_clear(dyn_str *d_str)
{
    d_str->size = 0;
    d_str->data[0] = '\0'; // Set the first character to null terminator
}

// Function to get the size of the dynamic string
unsigned char dyn_str_size(const dyn_str *d_str)
{
    return (unsigned char)d_str->size;
}

// Function to get the C string from the dynamic string
const char *dyn_str_c_dyn_str(const dyn_str *d_str)
{
    return d_str->data;
}

// Function to push a character to the back of the dynamic string
void dyn_str_push_back(dyn_str *d_str, char c)
{
    if (d_str->size + 1 >= d_str->capacity)
    {
        d_str->capacity *= 2; // Double the capacity
        d_str->data = (char *)realloc(d_str->data, d_str->capacity * sizeof(char));
    }
    d_str->data[d_str->size] = c;
    d_str->size++;
    d_str->data[d_str->size] = '\0'; // Ensure null termination
}

// Function to pop a character from the back of the dynamic string
char dyn_str_pop_back(dyn_str *d_str)
{
    char c = d_str->data[d_str->size - 1];
    d_str->size--;
    d_str->data[d_str->size] = '\0'; // Ensure null termination
    return c;
}

// Function to resize the dynamic string
void dyn_str_resize(dyn_str *d_str, unsigned char new_size)
{
    if (new_size + 1 > d_str->capacity)
    {
        d_str->capacity = new_size + 1;
        d_str->data = (char *)realloc(d_str->data, d_str->capacity * sizeof(char));
    }
    d_str->size = new_size;
    d_str->data[d_str->size] = '\0'; // Ensure null termination
}

// Function to validate an index
int dyn_str_valid_index(const dyn_str *d_str, unsigned char index)
{
    return index < d_str->size;
}

// Function to get a character at a specific index
char dyn_str_get(const dyn_str *d_str, unsigned char index)
{
    return d_str->data[index];
}

// Function to set a character at a specific index
void dyn_str_set(dyn_str *d_str, unsigned index, char c)
{
    d_str->data[index] = c;
}

// Function to find a character in the dynamic string
int dyn_str_find(const dyn_str *d_str, char c)
{
    for (unsigned char i = 0; i < d_str->size; i++)
    {
        if (d_str->data[i] == c)
        {
            return i; // Return the index of the first occurrence
        }
    }
    return -1; // Not found
}

// Function to remove a character at a specific index
void dyn_str_remove(dyn_str *dyn_str, unsigned char index)
{
    memmove(&dyn_str->data[index], &dyn_str->data[index + 1], dyn_str->size - index - 1);
    dyn_str->size--;
    dyn_str->data[dyn_str->size] = '\0'; // Null-terminate the string
}

// Function to insert a character at a specific index
void dyn_str_insert(dyn_str *dyn_str, unsigned char index, char c)
{
    // Resize if needed
    if (dyn_str->size + 1 >= dyn_str->capacity)
    {
        dyn_str->capacity = (dyn_str->capacity == 0) ? 1 : dyn_str->capacity * 2;
        dyn_str->data = realloc(dyn_str->data, dyn_str->capacity);
    }
    memmove(&dyn_str->data[index + 1], &dyn_str->data[index], dyn_str->size - index);
    dyn_str->data[index] = c;
    dyn_str->size++;
    dyn_str->data[dyn_str->size] = '\0'; // Null-terminate the string
}

// Function to swap two dynamic strings
void dyn_str_swap(dyn_str *dyn_str1, dyn_str *dyn_str2)
{
    dyn_str temp = *dyn_str1;
    *dyn_str1 = *dyn_str2;
    *dyn_str2 = temp;
}

// Function to copy a dynamic string
void dyn_str_copy(dyn_str *dest, const dyn_str *src)
{
    if (dest->data)
    {
        free(dest->data);
    }
    dest->size = src->size;
    dest->capacity = src->capacity;
    dest->data = malloc(dest->capacity);
    memcpy(dest->data, src->data, src->size);
    dest->data[dest->size] = '\0'; // Null-terminate the string
}

// Function to concatenate two dynamic strings
void dyn_str_concat(dyn_str *dest, const dyn_str *src)
{
    size_t new_size = dest->size + src->size;
    if (new_size >= dest->capacity)
    {
        dest->capacity = (new_size + 1) * 2; // Resize capacity
        dest->data = realloc(dest->data, dest->capacity);
    }
    memcpy(&dest->data[dest->size], src->data, src->size);
    dest->size = new_size;
    dest->data[dest->size] = '\0'; // Null-terminate the string
}
