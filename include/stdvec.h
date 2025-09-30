#pragma once

#include <stdint.h>
#include <stdlib.h>

#define VEC_CREATE(type) \
    type *vec = malloc(sizeof(type)); \
    VEC_INIT(vec); \
    return vec
#define VEC_INIT(x) \
    x->_data = NULL; \
    x->_size = 0;    \
    x->_capacity = 0
#define VEC_FINIT(x)   \
    if (x->_data)       \
    {                  \
        free(x->_data); \
    }                  \
    x->_data = NULL;    \
    x->_size = 0;       \
    x->_capacity = 0
#define VEC_DESTROY(x) \
    VEC_FINIT(x);      \
    free(x)
#define VEC_PUSH_BACK(x, val, type)                                     \
    if (x->_size >= x->_capacity)                                         \
    {                                                                   \
        size_t new_capacity = (x->_capacity == 0) ? 1 : x->_capacity * 2; \
        type *new_data = realloc(x->_data, new_capacity * sizeof(type)); \
        if (!new_data)                                                  \
        {                                                               \
            exit(EXIT_FAILURE);                                         \
        }                                                               \
        x->_data = new_data;                                             \
        x->_capacity = new_capacity;                                     \
    }                                                                   \
    x->_data[x->_size++] = val;
#define VEC_POP_BACK(x) \
    if (x->_size > 0)    \
    {                   \
        x->_size--;      \
    }
#define VEC_VALID_INDEX(x, index) return (0 <= index && index < x->_size)
#define VEC_GET(x, index) return (x->_data[index])
#define VEC_SET(x, index, val) \
    x->_data[index] = val
#define VEC_SIZE(x) (x->_size)
#define VEC_CAPACITY(x) (x->_capacity)
#define VEC_RESERVE(x, new_cap, type)                              \
    if (new_cap > x->_capacity)                                     \
    {                                                              \
        type *new_data = realloc(x->_data, new_cap * sizeof(type)); \
        if (!new_data)                                             \
        {                                                          \
            exit(EXIT_FAILURE);                                    \
        }                                                          \
        x->_data = new_data;                                        \
        x->_capacity = new_cap;                                     \
    }
#define VEC_RESIZE(x, new_size, type)                               \
    if (new_size > x->_capacity)                                     \
    {                                                               \
        type *new_data = realloc(x->_data, new_size * sizeof(type)); \
        if (!new_data)                                              \
        {                                                           \
            exit(EXIT_FAILURE);                                     \
        }                                                           \
        x->_data = new_data;                                         \
        x->_capacity = new_size;                                     \
    }                                                               \
    x->_size = new_size
#define VEC_CLEAR(x) \
    x->_size = 0
#define VEC_EMPTY(x) \
    x->_size == 0
#define VEC_FIND(x, val, type)           \
    for (size_t i = 0; i < x->_size; i++) \
    {                                    \
        if (x->_data[i] = val)           \
        {                                \
            return (int)i;               \
        }                                \
    }                                    \
    return -1    // Not found
#define VEC_FIND_COMP(x, pval, type, comp)           \
    for (size_t i = 0; i < x->_size; i++) \
    {                                    \
        if (comp(x->_data + i, pval))           \
        {                                \
            return (int)i;               \
        }                                \
    }                                    \
    return -1    // Not found
#define VEC_REMOVE(x, index)                     \
    for (size_t i = index; i < x->_size - 1; i++) \
    {                                            \
        x->_data[i] = x->_data[i + 1];             \
    }                                            \
    x->_size--
#define VEC_INSERT(x, index, val, type)                                 \
    if (x->_size >= x->_capacity)                                         \
    {                                                                   \
        size_t new_capacity = x->_capacity == 0 ? 1 : x->_capacity * 2;   \
        type *new_data = realloc(x->_data, new_capacity * sizeof(char)); \
        if (!new_data)                                                  \
        {                                                               \
            exit(EXIT_FAILURE);                                         \
        }                                                               \
        x->_data = new_data;                                             \
        x->_capacity = new_capacity;                                     \
    }                                                                   \
    for (size_t i = x->_size; i > index; i--)                            \
    {                                                                   \
        x->_data[i] = x->_data[i - 1];                                    \
    }                                                                   \
    x->_data[index] = val;                                             \
    x->_size++
#define VEC_SHRINK_TO_FIT(x, type)                                 \
    if (x->_size < x->_capacity)                                     \
    {                                                              \
        type *new_data = realloc(x->_data, x->_size * sizeof(type)); \
        if (!new_data && x->_size > 0)                              \
        {                                                          \
            exit(EXIT_FAILURE);                                    \
        }                                                          \
        x->_data = new_data;                                        \
        x->_capacity = x->_size;                                     \
    }
#define VEC_SWAP(x, y, type) \
    {                        \
        type temp = *x;      \
        *x = *y;             \
        *y = temp;           \
    }
#define VEC_COPY(dest, src, type)                          \
    {                                                      \
        if (dest->_data)                                    \
        {                                                  \
            free(dest->_data);                              \
        }                                                  \
        dest->_size = 0;                                    \
        dest->_capacity = 0;                                \
        if (src->_size > 0)                                 \
        {                                                  \
            dest->_data = malloc(src->_size * sizeof(type)); \
            if (!dest->_data)                               \
            {                                              \
                exit(EXIT_FAILURE);                        \
            }                                              \
            for (size_t i = 0; i < src->_size; i++)         \
            {                                              \
                dest->_data[i] = src->_data[i];              \
            }                                              \
            dest->_size = src->_size;                        \
            dest->_capacity = src->_size;                    \
        }                                                  \
    }
#define VEC_MOVE(dst,src) \
       if (dest->_data)                                    \
        {                                                  \
            free(dest->_data);                              \
        }                                                  \
        dest->_size = src->_size;                            \
        dest->_capacity = src->_capacity;                    \
        dest->_data = src->_data
#define VEC_REVERSE(x, type)                \
    {                                       \
        size_t left = 0;                    \
        size_t right = x->_size - 1;         \
        while (left < right)                \
        {                                   \
            type temp = x->_data[left];      \
            x->_data[left] = x->_data[right]; \
            x->_data[right] = temp;          \
            left++;                         \
            right--;                        \
        }                                   \
    }

//
// Vector declaration for char members
//
typedef struct
{
    char *_data;
    size_t _size;
    size_t _capacity;
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
    int *_data;
    size_t _size;
    size_t _capacity;
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
    double *_data;
    size_t _size;
    size_t _capacity;
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