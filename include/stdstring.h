#pragma once

#include <stdlib.h>

typedef union
{
    char stack[24];
    struct
    {
        char *data;
        size_t size;
        size_t capacity;
    } heap;
} string;

void string_create(string *str, const char c_str[], size_t size);
void string_destroy(string *str);
void string_clear(string *str);
size_t string_size(const string *str);
size_t string_capacity(const string *str);
const char *string_c_str(const string *str);
void string_push_back(string *str, char c);
void string_pop_back(string *str);
void string_reserve(string *str, size_t new_capacity);
void string_resize(string *str, size_t new_size);
int string_valid_index(const string *str, size_t index);
char string_get(const string *str, size_t index);
void string_set(string *str, size_t index, char c);
int string_find(const string *str, char c);
void string_remove(string *str, size_t index);
void string_insert(string *str, size_t index, char c);
void string_shrink_to_fit(string *str);
void string_swap(string *str1, string *str2);
void string_copy(const string *src, string *dest);
void string_concat(string *dest, const string *src);