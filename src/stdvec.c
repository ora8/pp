#include "stdvec.h"

//
// Vector implementation for differnet member types
// Created with Copilot
//

//
// Vector implementation for char members
//
char_vec *char_vec_create()
{
    VEC_CREATE(char_vec);
}

void char_vect_init(char_vec *vec)
{
    VEC_INIT(vec);
}

void char_vec_finit(char_vec *vec)  
{
    VEC_FINIT(vec);
}
void char_vec_destroy(char_vec *vec)
{
    VEC_DESTROY(vec);
}

void char_vec_push_back(char_vec *vec, char value)
{
    VEC_PUSH_BACK(vec, value, char);
}

void char_vec_pop_back(char_vec *vec)
{
    VEC_POP_BACK(vec);
}

int char_vec_valid_index(const char_vec *vec, size_t index)
{
    VEC_VALID_INDEX(vec, index);
}

char char_vec_get(const char_vec *vec, size_t index)
{
    VEC_GET(vec, index);
}

void char_vec_set(char_vec *vec, size_t index, char value)
{
    VEC_SET(vec, index, value);
}

size_t char_vec_size(const char_vec *vec)
{
    return vec->size;
}

void char_vec_reserve(char_vec *vec, size_t new_capacity)
{
    VEC_RESERVE(vec, new_capacity, char);
}

void char_vec_resize(char_vec *vec, size_t new_size)
{
    VEC_RESIZE(vec, new_size, char);
}

void char_vec_clear(char_vec *vec)
{
    VEC_CLEAR(vec);
}

int char_vec_find(const char_vec *vec, char value)
{
    VEC_FIND(vec, value, char);
}

void char_vec_remove(char_vec *vec, size_t index)
{
    VEC_REMOVE(vec, index);
}

void char_vec_insert(char_vec *vec, size_t index, char value)
{
    VEC_INSERT(vec, index, value, char);
}

void char_vec_shrink_to_fit(char_vec *vec)
{
    VEC_SHRINK_TO_FIT(vec, char);
}

void char_vec_swap(char_vec *vec1, char_vec *vec2)
{
    VEC_SWAP(vec1, vec2, char_vec);
}

void char_vec_copy(const char_vec *src, char_vec *dest)
{
    VEC_COPY(src, dest, char);
}

void char_vec_reverse(char_vec *vec)
{
    VEC_REVERSE(vec, char);
}   

//
// Vector implementation for int members
// Created with Copilot
// 
int_vec *int_vec_create()
{
    VEC_CREATE(int_vec);
}

void int_vec_init(int_vec *vec)
{
    VEC_INIT(vec);
}

void int_vec_finit(int_vec *vec)
{
    VEC_FINIT(vec);
}

void int_vec_destroy(int_vec *vec)
{
    VEC_DESTROY(vec);
}

void int_vec_push_back(int_vec *vec, int value)
{
    VEC_PUSH_BACK(vec, value, int);
}

void int_vec_pop_back(int_vec *vec)
{
    VEC_POP_BACK(vec);
}

void int_vec_reserve(int_vec *vec, size_t new_capacity)
{
    VEC_RESERVE(vec, new_capacity, int);
}

int int_vec_find(const int_vec *vec, int val)
{
    VEC_FIND(vec, val, int);
}

void int_vec_remove(int_vec *vec, size_t index)
{
    VEC_REMOVE(vec, index);
}

void int_vec_insert(int_vec *vec, size_t index, int value)
{
    VEC_INSERT(vec, index, value, int);
}

void int_vec_shrink_to_fit(int_vec *vec)
{
    VEC_SHRINK_TO_FIT(vec, int);
}

void int_vec_swap(int_vec *vec1, int_vec *vec2)
{
    VEC_SWAP(vec1, vec2, int_vec);
}

void int_vec_copy(const int_vec *src, int_vec *dest)
{
    VEC_COPY(src, dest, int);
}

void int_vec_reverse(int_vec *vec)
{
    VEC_REVERSE(vec, int);
}

int int_vec_valid_index(const int_vec *vec, size_t index)
{
    VEC_VALID_INDEX(vec, index);
}

int int_vec_get(const int_vec *vec, size_t index)
{
    VEC_GET(vec, index);
}

void int_vec_set(int_vec *vec, size_t index, int value)
{
    VEC_SET(vec, index, value);
}

//
// Vector implementation for double members
// Created with Copilot
//
double_vec *double_vec_create()
{
    VEC_CREATE(double_vec);
}

void double_vec_init(double_vec *vec)
{
    VEC_INIT(vec);
}

void double_vec_finit(double_vec *vec)
{
    VEC_FINIT(vec);
}
 
void double_vec_destroy(double_vec *vec)
{
    VEC_DESTROY(vec);
}       
void double_vec_push_back(double_vec *vec, double value)
{
    VEC_PUSH_BACK(vec, value, double);
}
void double_vec_pop_back(double_vec *vec)
{
    VEC_POP_BACK(vec);
}
int double_vec_valid_index(const double_vec *vec, size_t index)
{
    VEC_VALID_INDEX(vec, index);
}
double double_vec_get(const double_vec *vec, size_t index)
{
    VEC_GET(vec, index);
}   
void double_vec_set(double_vec *vec, size_t index, double value)
{
    VEC_SET(vec, index, value);
}
size_t double_vec_size(const double_vec *vec)
{
    return vec->size;
}
size_t double_vec_capacity(const double_vec *vec)
{
    return vec->capacity;
}
void double_vec_reserve(double_vec *vec, size_t new_capacity)
{
    VEC_RESERVE(vec, new_capacity, double);
}
void double_vec_resize(double_vec *vec, size_t new_size)
{
    VEC_RESIZE(vec, new_size, double);
}
void double_vec_clear(double_vec *vec) 
{
    vec->size = 0;
}
int double_vec_find(const double_vec *vec, double value)
{
    VEC_FIND(vec, value, double);
}
void double_vec_remove(double_vec *vec, size_t index)
{
    VEC_REMOVE(vec, index);
}
void double_vec_insert(double_vec *vec, size_t index, double value)
{
    VEC_INSERT(vec, index, value, double);
}
void double_vec_reverse(double_vec *vec)    
{
    VEC_REVERSE(vec, double);
}    
void double_vec_shrink_to_fit(double_vec *vec)  
{
    VEC_SHRINK_TO_FIT(vec, double);
}
void double_vec_swap(double_vec *vec1, double_vec *vec2)    
{
    VEC_SWAP(vec1, vec2, double_vec);
}
void double_vec_copy(const double_vec *src, double_vec *dest)  
{
    VEC_COPY(src, dest, double);
} 

//
// Vector implementation for pointer members
//
ptr_vec *ptr_vec_create()
{
    VEC_CREATE(ptr_vec);
}

void ptr_vec_init(ptr_vec *vec)
{
    VEC_INIT(vec);
}

void ptr_vec_finit(ptr_vec *vec)
{
    VEC_FINIT(vec);
}

void ptr_vec_destroy(ptr_vec *vec)  
{
    VEC_DESTROY(vec);
}

void ptr_vec_push_back(ptr_vec *vec, void *value)   
{
    VEC_PUSH_BACK(vec, value, void*);
}

void ptr_vec_pop_back(ptr_vec *vec) 
{
    VEC_POP_BACK(vec);
}

void *ptr_vec_get(const ptr_vec *vec, size_t index) 
{
    VEC_GET(vec, index);
}

void ptr_vec_set(ptr_vec *vec, size_t index, void *value)     
{
    VEC_SET(vec, index, value);
}

size_t ptr_vec_size(const ptr_vec *vec)     
{
    return vec->size;
}

size_t ptr_vec_capacity(const ptr_vec *vec)     
{
    return vec->capacity;
}

void ptr_vec_reserve(ptr_vec *vec, size_t new_capacity) 
{
    VEC_RESERVE(vec, new_capacity, void*);
}

void ptr_vec_resize(ptr_vec *vec, size_t new_size)
{
    VEC_RESIZE(vec, new_size, void*);
}

void ptr_vec_clear(ptr_vec *vec)    
{
    vec->size = 0;
}

int ptr_vec_find(const ptr_vec *vec, void *value)   
{
    VEC_FIND(vec, value, void*);
}

void ptr_vec_remove(ptr_vec *vec, size_t index) 
{
    VEC_REMOVE(vec, index);
}

void ptr_vec_insert(ptr_vec *vec, size_t index, void *value)    
{
    VEC_INSERT(vec, index, value, void*);
}

void ptr_vec_reverse(ptr_vec *vec)  
{
    VEC_REVERSE(vec, void*);
}

void ptr_vec_shrink_to_fit(ptr_vec *vec)    
{
    VEC_SHRINK_TO_FIT(vec, void*);
}

void ptr_vec_swap(ptr_vec *vec1, ptr_vec *vec2)   
{
    VEC_SWAP(vec1, vec2, ptr_vec);
}   

void ptr_vec_copy(const ptr_vec *src, ptr_vec *dest) 
{
    VEC_COPY(src, dest, void*);
}