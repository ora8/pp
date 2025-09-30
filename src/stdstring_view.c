#include <string.h>

#include "stdarray.h"
#include "stdstring_view.h"

//
// String view implementation
// Created with Copilot
//
string_view *string_view_create(const char c_str[], size_t size)
{
    string_view *sv = (string_view *)malloc(sizeof(string_view));
    if (!sv)
    {
        exit(EXIT_FAILURE);
    }
    string_view_init(sv, c_str, size);
    return sv;
}

void string_view_init(string_view *sv, const char c_str[], size_t size)
{
    sv->_c_str = (char *)c_str;
    sv->_size = size;
}

void string_view_destroy(string_view *sv)
{
    free(sv);
}

size_t string_view_size(const string_view *sv)
{
    return sv->_size;
}

const char *string_view_c_str(const string_view *sv)
{
    return sv->_c_str;
}

int string_view_valid_index(const string_view *sv, size_t index)
{
    return index < sv->_size;
}

char string_view_get(const string_view *sv, size_t index)
{
    return sv->_c_str[index];
}

int string_view_find(const string_view *sv, char c)
{
    for (size_t i = 0; i < sv->_size; i++)
    {
        if (sv->_c_str[i] == c)
        {
            return (int)i;
        }
    }
    return -1; // Not found
}

//
// Vector of string_view implementation
// Created with Copilot
//
string_view_vec *string_view_vec_create()
{
    VEC_CREATE(string_view_vec);
}

void string_view_vec_init(string_view_vec *vec)
{
    VEC_INIT(vec);
}

void string_view_vec_finit(string_view_vec *vec)
{
    VEC_FINIT(vec);
}

void string_view_vec_destroy(string_view_vec *vec)
{
    VEC_DESTROY(vec);
}

void string_view_vec_push_back(string_view_vec *vec, string_view *p_value)
{
    VEC_PUSH_BACK(vec, *p_value, string_view);
}

void string_view_vec_pop_back(string_view_vec *vec)
{
    VEC_POP_BACK(vec);
}

string_view string_view_vec_get(const string_view_vec *vec, size_t index)
{
    VEC_GET(vec, index);
}

void string_view_vec_set(string_view_vec *vec, size_t index, string_view *p_value)
{
    VEC_SET(vec, index, *p_value);
}

size_t string_view_vec_size(const string_view_vec *vec)
{
    VEC_SIZE(vec);
}

void string_view_vec_reserve(string_view_vec *vec, size_t new_capacity)
{
    VEC_RESERVE(vec, new_capacity, string_view);
}

void string_view_vec_resize(string_view_vec *vec, size_t new_size)
{
    VEC_RESIZE(vec, new_size, string_view);
}

void string_view_vec_clear(string_view_vec *vec)
{
    VEC_CLEAR(vec);
}

int string_view_vec_compare(const string_view *sv1, const string_view *sv2)
{
    return CHAR_ARRAY_COMPARE(sv1->_c_str, sv1->_size, sv2->_c_str, sv2->_size);
}

int string_view_vec_find(const string_view_vec *vec, string_view *p_value)
{
    VEC_FIND_COMP(vec, p_value, string_view, string_view_vec_compare);
}

void string_view_vec_remove(string_view_vec *vec, size_t index)
{
    VEC_REMOVE(vec, index);
}

void string_view_vec_insert(string_view_vec *vec, size_t index, string_view *p_value)
{
    VEC_INSERT(vec, index, *p_value, string_view);
 }

void string_view_vec_reverse(string_view_vec *vec)
{
    VEC_REVERSE(vec, string_view);
}

void string_view_vec_shrink_to_fit(string_view_vec *vec)
{
    VEC_SHRINK_TO_FIT(vec, string_view);
}

void string_view_vec_swap(string_view_vec *vec1, string_view_vec *vec2)
{
    VEC_SWAP(vec1, vec2, string_view_vec);
}

void string_view_vec_copy(string_view_vec *dest, const string_view_vec *src)
{
    VEC_COPY(dest, src, string_view_vec);
}

void string_view_vec_move(string_view_vec *dest, const string_view_vec *src)
{
    VEC_MOVE(dest, src);
}