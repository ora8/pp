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
    OPTION_INIT_NONE(result);                    \
    return result;

#define OPTION_CREATE(value, type)               \
    type *result = (type *)malloc(sizeof(type)); \
    OPTION_INIT(result, value);                  \
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

#define OPTION_SOME(option) \
    return option->_value

#define OPTION_HAS_SOME(option) \
    return option->_optional != NONE

typedef struct
{
    char _value;
    optional _optional;
} char_option;

char_option *char_option_create_none();
char_option *char_option_create_value(char value);
void char_option_init_none(char_option *option);
void char_option_init_value(char_option *option, char value);
void char_option_finit(char_option *option);
void char_option_destroy(char_option *option);
bool char_option_none(char_option *option);
char char_option_some(char_option *option);
bool char_option_has_some(char_option *option);

typedef struct
{
    short _value;
    optional _optional;
} short_option;

short_option *short_option_create_none();
short_option *short_option_create(short value);
void short_option_init_none(short_option *option);
void short_option_init(short_option *option, short value);
void short_option_finit(short_option *option);
void short_option_destroy(short_option *option);
bool short_option_none(short_option *option);
short short_option_some(short_option *option);
bool short_option_has_some(short_option *option);

typedef struct
{
    int _value;
    optional _optional;
} int_option;

int_option *int_option_create_none();
int_option *int_option_create(int value);
void int_option_init_none(int_option *option);
void int_option_init(int_option *option, int value);
void int_option_destroy(int_option *option);
bool int_option_none(int_option *option);
int int_option_some(int_option *option);
bool int_option_has_some(int_option *option);

typedef struct
{
    long _value;
    optional _optional;
} long_option;

long_option *long_option_create_none();
long_option *long_option_create(long value);
void long_option_init_none(long_option *option);
void long_option_init(long_option *option, long value);
void long_option_destroy(long_option *option);
bool long_option_none(long_option *option);
long long_option_some(long_option *option);
bool long_option_has_some(long_option *option);

typedef struct
{
    float _value;
    optional _optional;
} float_option;

float_option *float_option_create_none();
float_option *float_option_create(float value);
void float_option_init_none(float_option *option);
void float_option_init(float_option *option, float value);
void float_option_destroy(float_option *option);
bool float_option_none(float_option *option);
float float_option_some(float_option *option);
bool float_option_has_some(float_option *option);

typedef struct
{
    double _value;
    optional _optional;
} double_option;

double_option *double_option_create_none();
double_option *double_option_create(double value);
void double_option_init_none(double_option *option);
void double_option_init(double_option *option, double value);
void double_option_destroy(double_option *option);
bool double_option_none(double_option *option);
double double_option_some(double_option *option);
bool double_option_has_some(double_option *option);