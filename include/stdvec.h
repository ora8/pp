#pragma once

#include <stdint.h>
#include <stdlib.h>

#define VEC_CREATE(type) \
    type *vec = malloc(sizeof(type)); \
    VEC_INIT(vec); \
    return vec
#define VEC_INIT(x) \
    x->data = NULL; \
    x->size = 0;    \
    x->capacity = 0
#define VEC_FINIT(x)   \
    if (x->data)       \
    {                  \
        free(x->data); \
    }                  \
    x->data = NULL;    \
    x->size = 0;       \
    x->capacity = 0
#define VEC_DESTROY(x) \
    VEC_FINIT(x);      \
    free(x)
#define VEC_PUSH_BACK(x, val, type)                                     \
    if (x->size >= x->capacity)                                         \
    {                                                                   \
        size_t new_capacity = (x->capacity == 0) ? 1 : x->capacity * 2; \
        type *new_data = realloc(x->data, new_capacity * sizeof(type)); \
        if (!new_data)                                                  \
        {                                                               \
            exit(EXIT_FAILURE);                                         \
        }                                                               \
        x->data = new_data;                                             \
        x->capacity = new_capacity;                                     \
    }                                                                   \
    x->data[x->size++] = val;
#define VEC_POP_BACK(x) \
    if (x->size > 0)    \
    {                   \
        x->size--;      \
    }
#define VEC_VALID_INDEX(x, index) return (0 <= index && index < x->size)
#define VEC_GET(x, index) return (x->data[index])
#define VEC_SET(x, index, val) \
    x->data[index] = val
#define VEC_SIZE(x) (x->size)
#define VEC_CAPACITY(x) (x->capacity)
#define VEC_RESERVE(x, new_cap, type)                              \
    if (new_cap > x->capacity)                                     \
    {                                                              \
        type *new_data = realloc(x->data, new_cap * sizeof(type)); \
        if (!new_data)                                             \
        {                                                          \
            exit(EXIT_FAILURE);                                    \
        }                                                          \
        x->data = new_data;                                        \
        x->capacity = new_cap;                                     \
    }
#define VEC_RESIZE(x, new_size, type)                               \
    if (new_size > x->capacity)                                     \
    {                                                               \
        type *new_data = realloc(x->data, new_size * sizeof(type)); \
        if (!new_data)                                              \
        {                                                           \
            exit(EXIT_FAILURE);                                     \
        }                                                           \
        x->data = new_data;                                         \
        x->capacity = new_size;                                     \
    }                                                               \
    x->size = new_size
#define VEC_CLEAR(x) \
    x->size = 0
#define VEC_EMPTY(x) \
    x->size == 0
#define VEC_FIND(x, val, type)           \
    for (size_t i = 0; i < x->size; i++) \
    {                                    \
        if (x->data[i] = val)           \
        {                                \
            return (int)i;               \
        }                                \
    }                                    \
    return -1    // Not found
#define VEC_FIND_COMP(x, pval, type, comp)           \
    for (size_t i = 0; i < x->size; i++) \
    {                                    \
        if (comp(x->data + i, pval))           \
        {                                \
            return (int)i;               \
        }                                \
    }                                    \
    return -1    // Not found
#define VEC_REMOVE(x, index)                     \
    for (size_t i = index; i < x->size - 1; i++) \
    {                                            \
        x->data[i] = x->data[i + 1];             \
    }                                            \
    x->size--
#define VEC_INSERT(x, index, val, type)                                 \
    if (x->size >= x->capacity)                                         \
    {                                                                   \
        size_t new_capacity = x->capacity == 0 ? 1 : x->capacity * 2;   \
        type *new_data = realloc(x->data, new_capacity * sizeof(char)); \
        if (!new_data)                                                  \
        {                                                               \
            exit(EXIT_FAILURE);                                         \
        }                                                               \
        x->data = new_data;                                             \
        x->capacity = new_capacity;                                     \
    }                                                                   \
    for (size_t i = x->size; i > index; i--)                            \
    {                                                                   \
        x->data[i] = x->data[i - 1];                                    \
    }                                                                   \
    x->data[index] = val;                                             \
    x->size++
#define VEC_SHRINK_TO_FIT(x, type)                                 \
    if (x->size < x->capacity)                                     \
    {                                                              \
        type *new_data = realloc(x->data, x->size * sizeof(type)); \
        if (!new_data && x->size > 0)                              \
        {                                                          \
            exit(EXIT_FAILURE);                                    \
        }                                                          \
        x->data = new_data;                                        \
        x->capacity = x->size;                                     \
    }
#define VEC_SWAP(x, y, type) \
    {                        \
        type temp = *x;      \
        *x = *y;             \
        *y = temp;           \
    }
#define VEC_COPY(dest, src, type)                          \
    {                                                      \
        if (dest->data)                                    \
        {                                                  \
            free(dest->data);                              \
        }                                                  \
        dest->size = 0;                                    \
        dest->capacity = 0;                                \
        if (src->size > 0)                                 \
        {                                                  \
            dest->data = malloc(src->size * sizeof(type)); \
            if (!dest->data)                               \
            {                                              \
                exit(EXIT_FAILURE);                        \
            }                                              \
            for (size_t i = 0; i < src->size; i++)         \
            {                                              \
                dest->data[i] = src->data[i];              \
            }                                              \
            dest->size = src->size;                        \
            dest->capacity = src->size;                    \
        }                                                  \
    }
#define VEC_MOVE(dst,src) \
       if (dest->data)                                    \
        {                                                  \
            free(dest->data);                              \
        }                                                  \
        dest->size = src->size;                            \
        dest->capacity = src->capacity;                    \
        dest->data = src->data
#define VEC_REVERSE(x, type)                \
    {                                       \
        size_t left = 0;                    \
        size_t right = x->size - 1;         \
        while (left < right)                \
        {                                   \
            type temp = x->data[left];      \
            x->data[left] = x->data[right]; \
            x->data[right] = temp;          \
            left++;                         \
            right--;                        \
        }                                   \
    }

//
// Vector declaration for char members
//
typedef struct
{
    char *data;
    size_t size;
    size_t capacity;
} char_vec;

char_vec *char_vec_create();
void char_vec_init(char_vec *vec);
void char_vec_finit(char_vec *vec);
void char_vec_destroy(char_vec *vec);
void char_vec_push_back(char_vec *vec, char value);
void char_vec_pop_back(char_vec *vec);
char char_valid_index(const char_vec *vec, size_t index);
char char_vec_get(const char_vec *vec, size_t index);
void char_vec_set(char_vec *vec, size_t index, char value);
size_t char_vec_size(const char_vec *vec);
size_t char_vec_capacity(const char_vec *vec);
void char_vec_reserve(char_vec *vec, size_t new_capacity);
void char_vec_resize(char_vec *vec, size_t new_size);
void char_vec_clear(char_vec *vec);
int char_vec_find(const char_vec *vec, char value);
void char_vec_remove(char_vec *vec, size_t index);
void char_vec_insert(char_vec *vec, size_t index, char value);
void char_vec_reverse(char_vec *vec);
void char_vec_shrink_to_fit(char_vec *vec);
void char_vec_swap(char_vec *vec1, char_vec *vec2);
void char_vec_copy(char_vec *dest, const char_vec *src);
void char_vec_move(char_vec *dest, const char_vec *src);

//
// Vector declaration for int members
//
typedef struct
{
    int *data;
    size_t size;
    size_t capacity;
} int_vec;

int_vec *int_vec_create();
void int_vec_init(int_vec *vec);
void int_vec_finit(int_vec *vec);
void int_vec_destroy(int_vec *vec);
void int_vec_push_back(int_vec *vec, int value);
void int_vec_pop_back(int_vec *vec);
int int_vec_get(const int_vec *vec, size_t index);
void int_vec_set(int_vec *vec, size_t index, int value);
size_t int_vec_size(const int_vec *vec);
size_t int_vec_capacity(const int_vec *vec);
void int_vec_reserve(int_vec *vec, size_t new_capacity);
void int_vec_resize(int_vec *vec, size_t new_size);
void int_vec_clear(int_vec *vec);
int int_vec_find(const int_vec *vec, int value);
void int_vec_remove(int_vec *vec, size_t index);
void int_vec_insert(int_vec *vec, size_t index, int value);
void int_vec_reverse(int_vec *vec);
void int_vec_shrink_to_fit(int_vec *vec);
void int_vec_swap(int_vec *vec1, int_vec *vec2);
void int_vec_copy(int_vec *dest, const int_vec *src);
void int_vec_move(int_vec *dest, const int_vec *src);

//
// Vector declaration for double members
//
typedef struct
{
    double *data;
    size_t size;
    size_t capacity;
} double_vec;

double_vec *double_vec_create();
void double_vec_init(double_vec *vec);
void double_vec_finit(double_vec *vec);
void double_vec_destroy(double_vec *vec);
void double_vec_push_back(double_vec *vec, double value);
void double_vec_pop_back(double_vec *vec);
double double_vec_get(const double_vec *vec, size_t index);
void double_vec_set(double_vec *vec, size_t index, double value);
size_t double_vec_size(const double_vec *vec);
size_t double_vec_capacity(const double_vec *vec);
void double_vec_reserve(double_vec *vec, size_t new_capacity);
void double_vec_resize(double_vec *vec, size_t new_size);
void double_vec_clear(double_vec *vec);
int double_vec_find(const double_vec *vec, double value);
void double_vec_remove(double_vec *vec, size_t index);
void double_vec_insert(double_vec *vec, size_t index, double value);
void double_vec_reverse(double_vec *vec);
void double_vec_shrink_to_fit(double_vec *vec);
void double_vec_swap(double_vec *vec1, double_vec *vec2);
void double_vec_copy(double_vec *dest, const double_vec *src);
void double_vec_move(double_vec *dest, const double_vec *src);

//
// Vector declaration for pointer members
//
typedef struct
{
    void **data;
    size_t size;
    size_t capacity;
} ptr_vec;

ptr_vec *ptr_vec_create();
void ptr_vec_init(ptr_vec *vec);
void ptr_vec_finit(ptr_vec *vec);
void ptr_vec_destroy(ptr_vec *vec);
void ptr_vec_push_back(ptr_vec *vec, void *value);
void ptr_vec_pop_back(ptr_vec *vec);
void *ptr_vec_get(const ptr_vec *vec, size_t index);
void ptr_vec_set(ptr_vec *vec, size_t index, void *value);
size_t ptr_vec_size(const ptr_vec *vec);
size_t ptr_vec_capacity(const ptr_vec *vec);
void ptr_vec_reserve(ptr_vec *vec, size_t new_capacity);
void ptr_vec_resize(ptr_vec *vec, size_t new_size);
void ptr_vec_clear(ptr_vec *vec);
int ptr_vec_find(const ptr_vec *vec, void *value);
void ptr_vec_remove(ptr_vec *vec, size_t index);
void ptr_vec_insert(ptr_vec *vec, size_t index, void *value);
void ptr_vec_reverse(ptr_vec *vec);
void ptr_vec_shrink_to_fit(ptr_vec *vec);
void ptr_vec_swap(ptr_vec *vec1, ptr_vec *vec2);
void ptr_vec_copy(ptr_vec *dest, const ptr_vec *src);
void ptr_vec_move(ptr_vec *dest, const ptr_vec *src);
