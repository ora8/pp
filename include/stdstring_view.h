#pragma once

#include <stdlib.h>

#include "stdstring.h"
#include "stdvec.h"

//
// String view declaration
//
typedef struct
{
    char *c_str;
    size_t size;
} string_view;

string_view *string_view_create(const char c_str[], size_t size);
void string_view_init(string_view *sv, const char c_str[], size_t size);
void string_view_destroy(string_view *sv);
size_t string_view_size(const string_view *sv);
const char *string_view_c_str(const string_view *sv);
int string_view_valid_index(const string_view *sv, size_t index);
char string_view_get(const string_view *sv, size_t index);
int string_view_find(const string_view *sv, char c);                                

//
// Vector of string_view declaration
//
typedef ptr_vec string_view_vec;

void string_view_vec_create(string_view_vec *vec);
void string_view_vec_destroy(string_view_vec *vec);
void string_view_vec_push_back(string_view_vec *vec, string_view *p_value);
void string_view_vec_pop_back(string_view_vec *vec);
string_view *string_view_vec_get(const string_view_vec *vec, size_t index);
void string_view_vec_set(string_view_vec *vec, size_t index, string_view *p_value);
size_t string_view_vec_size(const string_view_vec *vec);
size_t string_view_vec_capacity(const string_view_vec *vec);
void string_view_vec_reserve(string_view_vec *vec, size_t new_capacity);
void string_view_vec_resize(string_view_vec *vec, size_t new_size);
void string_view_vec_clear(string_view_vec *vec);
int string_view_vec_find(const string_view_vec *vec, string_view *p_value);
void string_view_vec_remove(string_view_vec *vec, size_t index);
void string_view_vec_insert(string_view_vec *vec, size_t index, string_view *p_value);
void string_view_vec_reverse(string_view_vec *vec);
void string_view_vec_shrink_to_fit(string_view_vec *vec);
void string_view_vec_swap(string_view_vec *vec1, string_view_vec *vec2);
void string_view_vec_copy(const string_view_vec *src, string_view_vec *dest);
