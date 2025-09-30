#include "stdopt.h"

char_option *char_option_create_none()
{
    OPTION_CREATE_NONE(char_option);
}

char_option *char_option_create(char value)
{
    OPTION_CREATE(value, char_option);
}

void char_option_init_none(char_option *option)
{
    OPTION_INIT_NONE(option);
}

void char_option_init(char_option *option, char value)
{
    OPTION_INIT(option, value);
}

void char_option_destroy(char_option *option)
{
    OPTION_DESTROY(option);
}

bool char_option_none(char_option *option)
{
    OPTION_NONE(option);
}

char char_option_some(char_option *option)
{
    OPTION_SOME(option);
}

bool char_option_has_some(char_option *option)
{
    OPTION_HAS_SOME(option);
}

short_option *short_option_create_none()
{
    OPTION_CREATE_NONE(short_option);
}

short_option *short_option_create(short value)
{
    OPTION_CREATE(value, short_option);
}

void short_option_init_none(short_option *option)
{
    OPTION_INIT_NONE(option);
}

void short_option_init(short_option *option, short value)
{
    OPTION_INIT(option, value);
}

void short_option_destroy(short_option *option)
{
    OPTION_DESTROY(option);
}

bool short_option_none(short_option *option)
{
    OPTION_NONE(option);
}

short short_option_some(short_option *option)
{
    OPTION_SOME(option);
}

bool short_option_has_some(short_option *option)
{
    OPTION_HAS_SOME(option);
}

int_option *int_option_create_none()
{
    OPTION_CREATE_NONE(int_option);
}

int_option *int_option_create(int value)
{
    OPTION_CREATE(value, int_option);
}

void int_option_init_none(int_option *option)
{
    OPTION_INIT_NONE(option);
}

void int_option_init(int_option *option, int value)
{
    OPTION_INIT(option, value);
}

void int_option_destroy(int_option *option)
{
    OPTION_DESTROY(option);
}

bool int_option_none(int_option *option)
{
    OPTION_NONE(option);
}

int int_option_some(int_option *option)
{
    OPTION_SOME(option);
}

bool int_option_has_some(int_option *option)
{
    OPTION_HAS_SOME(option);
}

long_option *long_option_create_none()
{
    OPTION_CREATE_NONE(long_option);
}

long_option *long_option_create(long value)
{
    OPTION_CREATE(value, long_option);
}

void long_option_init_none(long_option *option)
{
    OPTION_INIT_NONE(option);
}

void long_option_init(long_option *option, long value)
{
    OPTION_INIT(option, value);
}

void long_option_destroy(long_option *option)
{
    OPTION_DESTROY(option);
}

bool long_option_none(long_option *option)
{
    OPTION_NONE(option);
}

long long_option_some(long_option *option)
{
    OPTION_SOME(option);
}

bool long_option_has_some(long_option *option)
{
    OPTION_HAS_SOME(option);
}

float_option *float_option_create_none()
{
    OPTION_CREATE_NONE(float_option);
}

float_option *float_option_create(float value)
{
    OPTION_CREATE(value, float_option);
}

void float_option_init_none(float_option *option)
{
    OPTION_INIT_NONE(option);
}
void float_option_init(float_option *option, float value)
{
    OPTION_INIT(option, value);
}

void float_option_destroy(float_option *option)
{
    OPTION_DESTROY(option);
}

bool float_option_none(float_option *option)
{
    OPTION_NONE(option);
}

float float_option_some(float_option *option)
{
    OPTION_SOME(option);
}

bool float_option_has_some(float_option *option)
{
    OPTION_HAS_SOME(option);
}

double_option *double_option_create_none()
{
    OPTION_CREATE_NONE(double_option);
}

double_option *double_option_create(double value)
{
    OPTION_CREATE(value, double_option);
}

void double_option_init_none(double_option *option)
{
    OPTION_INIT_NONE(option);
}

void double_option_init(double_option *option, double value)
{
    OPTION_INIT(option, value);
}

void double_option_destroy(double_option *option)
{
    OPTION_DESTROY(option);
}

bool double_option_none(double_option *option)
{
    OPTION_NONE(option);
}

double double_option_some(double_option *option)
{
    OPTION_SOME(option);
}

bool double_option_has_some(double_option *option)
{
    OPTION_HAS_SOME(option);
}