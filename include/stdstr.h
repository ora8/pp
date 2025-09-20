#pragma once

//
// Function macros for a structure like this
//
// typedef struct {
//  char *data;
//  unsigned char size,
// } str;
//

#define STR_CREATE(type, y)                   \
    type *st = (type *)malloc(sizeof(type)); \
    STR_INIT(st, y);                   \
    return st

#define STR_INIT(x, y)                            \
    if (y)                                        \
    {                                             \
        strncpy(x->data, y, sizeof(x->data) - 1); \
        x->data[sizeof(x->data) - 1] = '\0';      \
        x->size = (unsigned char)strlen(x->data); \
    }                                             \
    else                                          \
    {                                             \
        x->data[0] = '\0';                        \
        x->size = 0;                              \
    }
#define STR_DESTROY(x) \
    free(x)
#define STR_CLEAR(x) \
    x->size = 0;     \
    x->data[0] = '\0'
#define STR_SIZE(x) \
    return str->size
#define STR_C_STR(x) \
    return str->data
#define STR_PUSH_BACK(x,y) \
    x->data[x->size++] = c; \
    x->data[x->size] = '\0'
#define STR_POP_BACK(x) \
        char c = x->data[--x->size]; \
        x->data[x->size] = '\0'; \
        return c
#define STR_RESIZE(x,y) \
    if (y > sizeof(x->data) - 1) \
    { \
        return 1; \
    } \
    x->size = y; \
    x->data[y] = '\0'; \
    return 0
#define STR_VALID_INDEX(x,y) \
    return y >= x->size
#define STR_GET(x, y) \
    return x->data[y]
#define STR_SET(x,y,z) \
    x->data[y] = z
#define STR_FIND(x,y) \
    for (unsigned char i = 0; i < x->size; i++) \
    { \
        if (x->data[i] == y) \
        { \
            return i; \
        } \
    } \
    return -1
#define STR_REMOVE(x,y) \
   memmove(x->data + y, x->data + y + 1, x->size - y - 1); \
    x->size--; \
    x->data[x->size] = '\0'
#define STR_INSERT(x,y,z) \
    memmove(x->data + y + 1, x->data + y, x->size - y); \
    x->data[y] = z; \
    x->size++; \
    x->data[x->size] = '\0'
#define STR_SWAP(type,x,y) \
    type temp = *x; \
    *x = *y; \
    *y = temp
#define STR_COPY(x,y) \
    x->size = y->size; \
    strncpy(x->data, y->data, y->size); \
    x->data[x->size] = '\0'
#define STR_CONCAT(x,y) \
   strncat(x->data, y->data, y->size); \
    x->size += y->size; \
    x->data[x->size] = '\0'

//
// Small string (fixed size string with maximal 31 characters)
//
typedef struct {
    char data[31];
    unsigned char size;
} small_str;

small_str *small_str_create(const char *s);
void small_str_init(small_str *str, const char *s);
void small_str_destroy(small_str *str);
void small_str_clear(small_str *str);
unsigned char small_str_size(const small_str *str);
const char *small_str_c_str(const small_str *str);
void small_str_push_back(small_str *str, char c);
char small_str_pop_back(small_str *str);
int small_str_resize(small_str *str, unsigned char new_size);
int small_str_valid_index(const small_str *str, unsigned char index);
char small_str_get(const small_str *str, unsigned char index);
void small_str_set(small_str *str, unsigned index, char c);
int small_str_find(const small_str *str, char c);
void small_str_remove(small_str *str, unsigned char index);
void small_str_insert(small_str *str, unsigned char index, char c);
void small_str_swap(small_str *str1, small_str *str2);
void small_str_copy(small_str *dest, const small_str *src);
void small_str_concat(small_str *dest, const small_str *src);

//
// Medium string (fixed size string with maximal 63 characters)
//
typedef struct {
    char data[64];
    unsigned char size;
} medium_str;

medium_str *medium_str_create(const char *s);
void medium_str_init(medium_str *str, const char *s);
void medium_str_destroy(medium_str *str);
void medium_str_clear(medium_str *str);
unsigned char medium_str_size(const medium_str *str);
const char *medium_str_c_str(const medium_str *str);
void medium_str_push_back(medium_str *str, char c);
char medium_str_pop_back(medium_str *str);
int medium_str_resize(medium_str *str, unsigned char new_size);
int medium_str_valid_index(const medium_str *str, unsigned char index);
char medium_str_get(const medium_str *str, unsigned char index);
void medium_str_set(medium_str *str, unsigned index, char c);
int medium_str_find(const medium_str *str, char c);
void medium_str_remove(medium_str *str, unsigned char index);
void medium_str_insert(medium_str *str, unsigned char index, char c);
void medium_str_swap(medium_str *str1, medium_str *str2);
void medium_str_copy(medium_str *dest, const medium_str *src);
void medium_str_concat(medium_str *dest, const medium_str *src);

//
// String (fixed string with maximal 127 characters)
typedef struct {
    char data[128];
    unsigned char size;
} str;

str *str_create(const char *s);
void str_init(str *str, const char *s);
void str_destroy(str *str);
void str_clear(str *str);
unsigned char str_size(const str *str);
const char *str_c_str(const str *str);
void str_push_back(str *str, char c);
char str_pop_back(str *str);
int str_resize(str *str, unsigned char new_size);
int str_valid_index(const str *str, unsigned char index);
char str_get(const str *str, unsigned char index);
void str_set(str *str, unsigned index, char c);
int str_find(const str *str, char c);
void str_remove(str *str, unsigned char index);
void str_insert(str *str, unsigned char index, char c);
void str_swap(str *str1, str *str2);
void str_copy(str *dest, const str *src);
void str_concat(str *dest, const str *src);

//
// Large string (fixed string with maximal 255 characters)
typedef struct {
    char data[256];
    unsigned char size;
} large_str;

large_str *large_str_create(const char *s);
void large_str_init(large_str *large_str, const char *s);
void large_str_delarge_stroy(large_str *large_str);
void large_str_clear(large_str *large_str);
unsigned char large_str_size(const large_str *large_str);
const char *large_str_c_large_str(const large_str *large_str);
void large_str_push_back(large_str *large_str, char c);
char large_str_pop_back(large_str *large_str);
int large_str_resize(large_str *large_str, unsigned char new_size);
int large_str_valid_index(const large_str *large_str, unsigned char index);
char large_str_get(const large_str *large_str, unsigned char index);
void large_str_set(large_str *large_str, unsigned index, char c);
int large_str_find(const large_str *large_str, char c);
void large_str_remove(large_str *large_str, unsigned char index);
void large_str_insert(large_str *large_str, unsigned char index, char c);
void large_str_swap(large_str *large_str1, large_str *large_str2);
void large_str_copy(large_str *dest, const large_str *src);
void large_str_concat(large_str *dest, const large_str *src);

//
// Dynamic string (string with variable length, resided on the heap)
//
typedef struct {
    char *data; // Pointer to the string data
    size_t size; // Size of the string
    size_t capacity;    // Capacity of the string
} dyn_str;

dyn_str *dyn_str_create(const char *s);
void dyn_str_init(dyn_str *dyn_str, const char *s);
void dyn_str_dedyn_stroy(dyn_str *dyn_str);
void dyn_str_clear(dyn_str *dyn_str);
unsigned char dyn_str_size(const dyn_str *dyn_str);
const char *dyn_str_c_dyn_str(const dyn_str *dyn_str);
void dyn_str_push_back(dyn_str *dyn_str, char c);
char dyn_str_pop_back(dyn_str *dyn_str);
void dyn_str_resize(dyn_str *dyn_str, unsigned char new_size);
int dyn_str_valid_index(const dyn_str *dyn_str, unsigned char index);
char dyn_str_get(const dyn_str *dyn_str, unsigned char index);
void dyn_str_set(dyn_str *dyn_str, unsigned index, char c);
int dyn_str_find(const dyn_str *dyn_str, char c);
void dyn_str_remove(dyn_str *dyn_str, unsigned char index);
void dyn_str_insert(dyn_str *dyn_str, unsigned char index, char c);
void dyn_str_swap(dyn_str *dyn_str1, dyn_str *dyn_str2);
void dyn_str_copy(dyn_str *dest, const dyn_str *src);
void dyn_str_concat(dyn_str *dest, const dyn_str *src);