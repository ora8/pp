#pragma once

#include <stdlib.h>

typedef union
{
    struct 
    {
        unsigned char _size;
        char _data[23];
    } _stack;
    struct
    {
        size_t _capacity;
        size_t _size;
        char *_data;
    } _heap;
} string;

string *string_create(const char c_str[]);
void string_init(string *str, const char c_str[]);
void string_finit(string *str);
void string_destroy(string *str);
void string_clear(string *str);
int string_empty(const string *str);
size_t string_size(const string *str);
size_t string_capacity(const string *str);
const char *string_c_str(const string *str);
void string_push_back(string *str, char c);
char string_pop_back(string *str);
void string_reserve(string *str, size_t new_capacity);
void string_resize(string *str, size_t new_size);
int string_valid_index(const string *str, size_t index);
char string_get(const string *str, size_t index);
void string_set(string *str, size_t index, char c);
int string_find(const string *str, char c);
void string_remove(string *str, size_t index);
void string_insert_char(string *str, size_t index, char c);
void string_insert_str(string *str, size_t index, const char s[]);
void string_insert_string(string *str, size_t index, const string *str2);
void string_shrink_to_fit(string *str);
void string_swap(string *str1, string *str2);
void string_clone(string *dst, const string *src);
void string_move(string *dst, string *src);
void string_concat(string *dst, const string *src);