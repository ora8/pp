#pragma once

#include <stdbool.h>
#include <stdlib.h>

typedef enum
{
    NONE,
    SOME
} optional;

#define OPTION_CREATE_NONE(type)                 \
    type *result = (type *)malloc(sizeof(type)); \
    OPTION_SET_NONE(result);                    \
    return result;

#define OPTION_CREATE(value, type)               \
    type *result = (type *)malloc(sizeof(type)); \
    OPTION_SET_SOME(result, value);                  \
    return result;

#define OPTION_INIT_NONE(option) \
    option->_optional = NONE

#define OPTION_INIT(option, value) \
    option->_value = value;        \
    option->_optional = SOME

#define OPTION_DESTROY(option) \
    free(option)

#define OPTION_NONE(option) \
    return option->_optional == NONE

#define OPTION_SET_NONE(option) \
    option->_optional = NONE;

#define OPTION_SOME(option) \
    return option->_value

#define OPTION_SET_SOME(option, value) \
    option->_value = value;        \
    option->_optional = SOME

#define OPTION_HAS_SOME(option) \
    return option->_optional != NONE

typedef struct
{
    char _value;
    optional _optional;
} opt_char;

opt_char *opt_char_create_none();
opt_char *opt_char_create_value(char value);
void opt_char_finit(opt_char *option);
void opt_char_destroy(opt_char *option);
bool opt_char_none(opt_char *option);
void opt_char_set_none(opt_char *option);
char opt_char_some(opt_char *option);
void opt_char_set_some(opt_char *option, char value);
bool opt_char_has_some(opt_char *option);

typedef struct
{
    short _value;
    optional _optional;
} opt_short;

opt_short *opt_short_create_none();
opt_short *opt_short_create(short value);
void opt_short_destroy(opt_short *option);
bool opt_short_none(opt_short *option);
void opt_short_set_none(opt_short *option);
short opt_short_some(opt_short *option);
void opt_short_set_some(opt_short *option, short value);
bool opt_short_has_some(opt_short *option);

typedef struct
{
    int _value;
    optional _optional;
} opt_int;

opt_int *opt_int_create_none();
opt_int *opt_int_create(int value);
void opt_int_destroy(opt_int *option);
bool opt_int_none(opt_int *option);
void opt_int_set_none(opt_int *option);
int opt_int_some(opt_int *option);
void opt_int_set_some(opt_int *option, int value);
bool opt_int_has_some(opt_int *option);

typedef struct
{
    long _value;
    optional _optional;
} opt_long;

opt_long *opt_long_create_none();
opt_long *opt_long_create(long value);
void opt_long_destroy(opt_long *option);
bool opt_long_none(opt_long *option);
void opt_long_set_none(opt_long *option);
long opt_long_some(opt_long *option);
void opt_long_set_some(opt_long *option, long value);
bool opt_long_has_some(opt_long *option);

typedef struct
{
    float _value;
    optional _optional;
} opt_float;

opt_float *opt_float_create_none();
opt_float *opt_float_create(float value);
void opt_float_destroy(opt_float *option);
bool opt_float_none(opt_float *option);
void opt_float_set_none(opt_float *option);
float opt_float_some(opt_float *option);
void opt_float_set_some(opt_float *option, float value);
bool opt_float_has_some(opt_float *option);

typedef struct
{
    double _value;
    optional _optional;
} opt_double;

opt_double *opt_double_create_none();
opt_double *opt_double_create(double value);
void opt_double_destroy(opt_double *option);
bool opt_double_none(opt_double *option);
void opt_double_set_none(opt_double *option);
double opt_double_some(opt_double *option);
void opt_double_set_some(opt_double *option, double value);
bool opt_double_has_some(opt_double *option);

#define PTR_OPTION_CREATE_NONE(option_type) \
    option_type *option = (option_type *)malloc(sizeof(option_type)); \
    if (!option) \
    { \
        exit(EXIT_FAILURE); \
    } \
    PTR_OPTION_SET_NONE(option); \
    return option

#define PTR_OPTION_CREATE(value, option_type) \
    option_type *option = (option_type *)malloc(sizeof(option_type)); \
    if (!option) \
    { \
        exit(EXIT_FAILURE); \
    } \
    PTR_OPTION_SET_SOME(option, value); \
    return option

#define PTR_OPTION_DESTROY(option) \
    free(option)

#define PTR_OPTION_NONE(option) \
    !option->_value

#define PTR_OPTION_SET_NONE(option) \
    option->_value = NULL

#define PTR_OPTION_SOME(option) \
    return option->_value

#define PTR_OPTION_SET_SOME(option, value) \
    option->_value = value

#define PTR_OPTION_HAS_SOME(option) \
    option->_value

typedef struct
{
    char *_value;
} opt_pchar;

opt_pchar *opt_pchar_create_none();
opt_pchar *opt_pchar_create(char *value);
void opt_pchar_destroy(opt_pchar *option);
bool opt_pchar_none(opt_pchar *option);
void opt_pchar_set_none(opt_pchar *option);
char *opt_pchar_some(opt_pchar *option);
void opt_pchar_set_some(opt_pchar *option, char *value);
bool opt_pchar_has_some(opt_pchar *option);

typedef struct
{
    short *_value;
} opt_pshort;

opt_pshort *opt_pshort_create_none();
opt_pshort *opt_pshort_create(short *value);
void opt_pshort_destroy(opt_pshort *option);
bool opt_pshort_none(opt_pshort *option);
void opt_pshort_set_none(opt_pshort *option);
short *opt_pshort_some(opt_pshort *option);
void opt_pshort_set_some(opt_pshort *option, short *value);
bool opt_pshort_has_some(opt_pshort *option);

typedef struct
{
    int *_value;
} opt_pint;

opt_pint *opt_pint_create_none();
opt_pint *opt_pint_create(int *value);
void opt_pint_destroy(opt_pint *option);
bool opt_pint_none(opt_pint *option);
void opt_pint_set_none(opt_pint *option);
int *opt_pint_some(opt_pint *option);
void opt_pint_set_some(opt_pint *option, int *value);
bool opt_pint_has_some(opt_pint *option);

typedef struct
{
    long *_value;
} opt_plong;

opt_plong *opt_plong_create_none();
opt_plong *opt_plong_create(long *value);
void opt_plong_destroy(opt_plong *option);
bool opt_plong_none(opt_plong *option);
void opt_plong_set_none(opt_plong *option);
long *opt_plong_some(opt_plong *option);
void opt_plong_set_some(opt_plong *option, long *value);
bool opt_plong_has_some(opt_plong *option);

typedef struct
{
    float *_value;
} opt_pfloat;

opt_pfloat *opt_pfloat_create_none();
opt_pfloat *opt_pfloat_create(float *value);
void opt_pfloat_destroy(opt_pfloat *option);
bool opt_pfloat_none(opt_pfloat *option);
float *opt_pfloat_some(opt_pfloat *option);
void opt_pfloat_set_none(opt_pfloat *option);
void opt_pfloat_set_some(opt_pfloat *option, float *value);
bool opt_pfloat_has_some(opt_pfloat *option);

typedef struct
{
    double *_value;
} opt_pdouble;

opt_pdouble *opt_pdouble_create_none();
opt_pdouble *opt_pdouble_create(double *value);
void opt_pdouble_destroy(opt_pdouble *option);
bool opt_pdouble_none(opt_pdouble *option);
void opt_pdouble_set_none(opt_pdouble *option);
double *opt_pdouble_some(opt_pdouble *option);
void opt_pdouble_set_some(opt_pdouble *option, double *value);
bool opt_pdouble_has_some(opt_pdouble *option);