#include "stdopt.h"

opt_char *opt_char_create_none()
{
    OPTION_CREATE_NONE(opt_char);
}

opt_char *opt_char_create(char value)
{
    OPTION_CREATE(value, opt_char);
}

void opt_char_destroy(opt_char *option)
{
    OPTION_DESTROY(option);
}

bool opt_char_none(opt_char *option)
{
    OPTION_NONE(option);
}

void opt_char_set_none(opt_char *option)
{
    OPTION_INIT_NONE(option);
}

char opt_char_some(opt_char *option)
{
    OPTION_SOME(option);
}

void opt_char_set_some(opt_char *option, char value)
{
    OPTION_INIT(option, value);
}

bool opt_char_has_some(opt_char *option)
{
    OPTION_HAS_SOME(option);
}

opt_short *opt_short_create_none()
{
    OPTION_CREATE_NONE(opt_short);
}

opt_short *opt_short_create(short value)
{
    OPTION_CREATE(value, opt_short);
}

void opt_short_destroy(opt_short *option)
{
    OPTION_DESTROY(option);
}

bool opt_short_none(opt_short *option)
{
    OPTION_NONE(option);
}

void opt_short_set_none(opt_short *option)
{
    OPTION_INIT_NONE(option);
}

short opt_short_some(opt_short *option)
{
    OPTION_SOME(option);
}

void opt_short_set_some(opt_short *option, short value)
{
    OPTION_INIT(option, value);
}

bool opt_short_has_some(opt_short *option)
{
    OPTION_HAS_SOME(option);
}

opt_int *opt_int_create_none()
{
    OPTION_CREATE_NONE(opt_int);
}

opt_int *opt_int_create(int value)
{
    OPTION_CREATE(value, opt_int);
}

void opt_int_destroy(opt_int *option)
{
    OPTION_DESTROY(option);
}

bool opt_int_none(opt_int *option)
{
    OPTION_NONE(option);
}

void opt_int_set_none(opt_int *option)
{
    OPTION_INIT_NONE(option);
}

int opt_int_some(opt_int *option)
{
    OPTION_SOME(option);
}

void opt_int_set_some(opt_int *option, int value)
{
    OPTION_INIT(option, value);
}

bool opt_int_has_some(opt_int *option)
{
    OPTION_HAS_SOME(option);
}

opt_long *opt_long_create_none()
{
    OPTION_CREATE_NONE(opt_long);
}

opt_long *opt_long_create(long value)
{
    OPTION_CREATE(value, opt_long);
}

void opt_long_destroy(opt_long *option)
{
    OPTION_DESTROY(option);
}

bool opt_long_none(opt_long *option)
{
    OPTION_NONE(option);
}

void opt_long_set_none(opt_long *option)
{
    OPTION_INIT_NONE(option);
}

long opt_long_some(opt_long *option)
{
    OPTION_SOME(option);
}

void opt_long_set_some(opt_long *option, long value)
{
    OPTION_INIT(option, value);
}

bool opt_long_has_some(opt_long *option)
{
    OPTION_HAS_SOME(option);
}

opt_float *opt_float_create_none()
{
    OPTION_CREATE_NONE(opt_float);
}

opt_float *opt_float_create(float value)
{
    OPTION_CREATE(value, opt_float);
}

void opt_float_destroy(opt_float *option)
{
    OPTION_DESTROY(option);
}

bool opt_float_none(opt_float *option)
{
    OPTION_NONE(option);
}

void opt_float_set_none(opt_float *option)
{
    OPTION_INIT_NONE(option);
}

float opt_float_some(opt_float *option)
{
    OPTION_SOME(option);
}

void opt_float_set_some(opt_float *option, float value)
{
    OPTION_INIT(option, value);
}

bool opt_float_has_some(opt_float *option)
{
    OPTION_HAS_SOME(option);
}

opt_double *opt_double_create_none()
{
    OPTION_CREATE_NONE(opt_double);
}

opt_double *opt_double_create(double value)
{
    OPTION_CREATE(value, opt_double);
}

void opt_double_destroy(opt_double *option)
{
    OPTION_DESTROY(option);
}

bool opt_double_none(opt_double *option)
{
    OPTION_NONE(option);
}

void opt_double_set_none(opt_double *option)
{
    OPTION_INIT_NONE(option);
}

double opt_double_some(opt_double *option)
{
    OPTION_SOME(option);
}

void opt_double_set_some(opt_double *option, double value)
{
    OPTION_INIT(option, value);
}

bool opt_double_has_some(opt_double *option)
{
    OPTION_HAS_SOME(option);
}

opt_pchar *opt_pchar_create_none()
{
    PTR_OPTION_CREATE_NONE(opt_pchar);
}

opt_pchar *opt_pchar_create(char *value)
{
    PTR_OPTION_CREATE(value, opt_pchar);
}

void opt_pchar_destroy(opt_pchar *option)
{
    PTR_OPTION_DESTROY(option);
}

bool opt_pchar_none(opt_pchar *option)
{
    PTR_OPTION_NONE(option);
}

void opt_pchar_set_none(opt_pchar *option)
{
    PTR_OPTION_SET_NONE(option);
}

char *opt_pchar_some(opt_pchar *option)
{
    PTR_OPTION_SOME(option);
}

void opt_pchar_set_some(opt_pchar *option, char *value)
{
    PTR_OPTION_SET_SOME(option, value);
}

bool opt_pchar_has_some(opt_pchar *option)
{
    PTR_OPTION_HAS_SOME(option);
}

opt_pshort *opt_pshort_create_none()
{
    PTR_OPTION_CREATE_NONE(opt_pshort);
}

opt_pshort *opt_pshort_create(short *value)
{
    PTR_OPTION_CREATE(value, opt_pshort);
}

void opt_pshort_destroy(opt_pshort *option)
{
    PTR_OPTION_DESTROY(option);
}

bool opt_pshort_none(opt_pshort *option)
{
    PTR_OPTION_NONE(option);
}

void opt_pshort_set_none(opt_pshort *option)
{
    PTR_OPTION_SET_NONE(option);
}

short *opt_pshort_some(opt_pshort *option)
{
    PTR_OPTION_SOME(option);
}

void opt_pshort_set_some(opt_pshort *option, short *value)
{
    PTR_OPTION_SET_SOME(option, value);
}

bool opt_pshort_has_some(opt_pshort *option)
{
    PTR_OPTION_HAS_SOME(option);
}

opt_pint *opt_pint_create_none()
{
    PTR_OPTION_CREATE_NONE(opt_pint);
}

opt_pint *opt_pint_create(int *value)
{
    PTR_OPTION_CREATE(value, opt_pint);
}

void opt_pint_destroy(opt_pint *option)
{
    PTR_OPTION_DESTROY(option);
}

bool opt_pint_none(opt_pint *option)
{
    PTR_OPTION_NONE(option);
}

void opt_pint_set_none(opt_pint *option)
{
    PTR_OPTION_SET_NONE(option);
}

int *opt_pint_some(opt_pint *option)
{
    PTR_OPTION_SOME(option);
}

void opt_pint_set_some(opt_pint *option, int *value)
{
    PTR_OPTION_SET_SOME(option, value);
}

bool opt_pint_has_some(opt_pint *option)
{
    PTR_OPTION_HAS_SOME(option);
}

opt_plong *opt_plong_create_none()
{
    PTR_OPTION_CREATE_NONE(opt_plong);
}

opt_plong *opt_plong_create(long *value)
{
    PTR_OPTION_CREATE(value, opt_plong);
}

void opt_plong_destroy(opt_plong *option)
{
    PTR_OPTION_DESTROY(option);
}

bool opt_plong_none(opt_plong *option)
{
    PTR_OPTION_NONE(option);
}

void opt_plong_set_none(opt_plong *option)
{
    PTR_OPTION_SET_NONE(option);
}

long *opt_plong_some(opt_plong *option)
{
    PTR_OPTION_SOME(option);
}

void opt_plong_set_some(opt_plong *option, long *value)
{
    PTR_OPTION_SET_SOME(option, value);
}

bool opt_plong_has_some(opt_plong *option)
{
    PTR_OPTION_HAS_SOME(option);
}

opt_pfloat *opt_pfloat_create_none()
{
    PTR_OPTION_CREATE_NONE(opt_pfloat);
}

opt_pfloat *opt_pfloat_create(float *value)
{
    PTR_OPTION_CREATE(value, opt_pfloat);
}

void opt_pfloat_destroy(opt_pfloat *option)
{
    PTR_OPTION_DESTROY(option);
}

bool opt_pfloat_none(opt_pfloat *option)
{
    PTR_OPTION_NONE(option);
}

void opt_pfloat_set_none(opt_pfloat *option)
{
    PTR_OPTION_SET_NONE(option);
}

float *opt_pfloat_some(opt_pfloat *option)
{
    PTR_OPTION_SOME(option);
}

void opt_pfloat_set_some(opt_pfloat *option, float *value)
{
    PTR_OPTION_SET_SOME(option, value);
}

bool opt_pfloat_has_some(opt_pfloat *option)
{
    PTR_OPTION_HAS_SOME(option);
}

opt_pdouble *opt_pdouble_create_none()
{
    PTR_OPTION_CREATE_NONE(opt_pdouble);
}

opt_pdouble *opt_pdouble_create(double *value)
{
    PTR_OPTION_CREATE(value, opt_pdouble);
}

void opt_pdouble_destroy(opt_pdouble *option)
{
    PTR_OPTION_DESTROY(option);
}

bool opt_pdouble_none(opt_pdouble *option)
{
    PTR_OPTION_NONE(option);
}

void opt_pdouble_set_none(opt_pdouble *option)
{
    PTR_OPTION_SET_NONE(option);
}

double *opt_pdouble_some(opt_pdouble *option)
{
    PTR_OPTION_SOME(option);
}

void opt_pdouble_set_some(opt_pdouble *option, double *value)
{
    PTR_OPTION_SET_SOME(option, value);
}

bool opt_pdouble_has_some(opt_pdouble *option)
{
    PTR_OPTION_HAS_SOME(option);
}
