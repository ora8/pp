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
void string_view_vector_create(string_view_vector *vec)
{
    ptr_vec_create(vec);
}
void string_view_vector_destroy(string_view_vector *vec)
{
    ptr_vec_destroy(vec);
}
void string_view_vector_push_back(string_view_vector *vec, string_view *p_value)
{
    ptr_vec_push_back(vec, (void *)p_value);
}
void string_view_vector_pop_back(string_view_vector *vec)
{
    ptr_vec_pop_back(vec);
}
string_view *string_view_vector_get(const string_view_vector *vec, size_t index)
{
    return (string_view *)ptr_vec_get(vec, index);
}
void string_view_vector_set(string_view_vector *vec, size_t index, string_view *p_value)
{
    ptr_vec_set(vec, index, (void *)p_value);
}
size_t string_view_vector_size(const string_view_vector *vec)
{
    return ptr_vec_size(vec);
}
void string_view_vector_reserve(string_view_vector *vec, size_t new_capacity)
{
    ptr_vec_reserve(vec, new_capacity);
}
void string_view_vector_resize(string_view_vector *vec, size_t new_size)
{
    ptr_vec_resize(vec, new_size);
}
void string_view_vector_clear(string_view_vector *vec)
{
    ptr_vec_clear(vec);
}
int string_view_vector_find(const string_view_vector *vec, string_view *p_value)
{
    return ptr_vec_find(vec, (void *)p_value);
}
void string_view_vector_remove(string_view_vector *vec, size_t index)
{
    ptr_vec_remove(vec, index);
}
void string_view_vector_insert(string_view_vector *vec, size_t index, string_view *p_value)
{
    ptr_vec_insert(vec, index, (void *)p_value);
}
void string_view_vector_reverse(string_view_vector *vec)
{
    ptr_vec_reverse(vec);
}
void string_view_vector_shrink_to_fit(string_view_vector *vec)
{
    ptr_vec_shrink_to_fit(vec);
}
void string_view_vector_swap(string_view_vector *vec1, string_view_vector *vec2)
{
    ptr_vec_swap(vec1, vec2);
}
void string_view_vector_copy(const string_view_vector *src, string_view_vector *dest)
{
    ptr_vec_copy(src, dest);
}
