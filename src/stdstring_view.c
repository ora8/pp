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
    sv->c_str = (char *)c_str;
    sv->size = size;
}

void string_view_destroy(string_view *sv)
{
    free(sv);
}

size_t string_view_size(const string_view *sv)
{
    return sv->size;
}

const char *string_view_c_str(const string_view *sv)
{
    return sv->c_str;
}

int string_view_valid_index(const string_view *sv, size_t index)
{
    return 0 <= index && index < sv->size;
}

char string_view_get(const string_view *sv, size_t index)
{
    return sv->c_str[index];
}

int string_view_find(const string_view *sv, char c)
{
    for (size_t i = 0; i < sv->size; i++)
    {
        if (sv->c_str[i] == c)
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
    ptr_vec_init(vec);
}

void string_view_vec_finit(string_view_vec *vec)
{
    ptr_vec_finit(vec);

}
void string_view_vec_destroy(string_view_vec *vec)
{
    ptr_vec_destroy(vec);
}
void string_view_vec_push_back(string_view_vec *vec, string_view *p_value)
{
    ptr_vec_push_back(vec, (void *)p_value);
}
void string_view_vec_pop_back(string_view_vec *vec)
{
    ptr_vec_pop_back(vec);
}
string_view *string_view_vec_get(const string_view_vec *vec, size_t index)
{
    return (string_view *)ptr_vec_get(vec, index);
}
void string_view_vec_set(string_view_vec *vec, size_t index, string_view *p_value)
{
    ptr_vec_set(vec, index, (void *)p_value);
}
size_t string_view_vec_size(const string_view_vec *vec)
{
    return ptr_vec_size(vec);
}
void string_view_vec_reserve(string_view_vec *vec, size_t new_capacity)
{
    ptr_vec_reserve(vec, new_capacity);
}
void string_view_vec_resize(string_view_vec *vec, size_t new_size)
{
    ptr_vec_resize(vec, new_size);
}
void string_view_vec_clear(string_view_vec *vec)
{
    ptr_vec_clear(vec);
}
int string_view_vec_find(const string_view_vec *vec, string_view *p_value)
{
    return ptr_vec_find(vec, (void *)p_value);
}
void string_view_vec_remove(string_view_vec *vec, size_t index)
{
    ptr_vec_remove(vec, index);
}
void string_view_vec_insert(string_view_vec *vec, size_t index, string_view *p_value)
{
    ptr_vec_insert(vec, index, (void *)p_value);
}
void string_view_vec_reverse(string_view_vec *vec)
{
    ptr_vec_reverse(vec);
}
void string_view_vec_shrink_to_fit(string_view_vec *vec)
{
    ptr_vec_shrink_to_fit(vec);
}
void string_view_vec_swap(string_view_vec *vec1, string_view_vec *vec2)
{
    ptr_vec_swap(vec1, vec2);
}
void string_view_vec_copy(const string_view_vec *src, string_view_vec *dest)
{
    ptr_vec_copy(src, dest);
}
