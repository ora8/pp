
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>

#include "stdconv.h"

static error str_to_int(const char *str, size_t size, int *pvalue)
{
    int number = 0;
    int sign = 1; // 1 for positive, -1 for negative
    int index = 0;

    // Skip leading whitespace
    while (index < size && isspace(str[index]))
    {
        index++;
    }
 
    if (index == size)
    {
        return NONE;
    }

    // Handle optional sign
    char ch = str[index];
    if (ch == '-')
    {
        sign = -1;
        index++;
    }
    else if (ch == '+')
    {
        index++;
    }

    if (index == size)
    {
        return INVALID;
    }
    ch = str[index];
    // Convert string to integer
    while (index < size && '0' <= ch && ch <= '9')
    {
        int digit = ch - '0';

        // Check for overflow
        if (number > (INT_MAX - digit) / 10)
        {
            *pvalue = (sign == 1) ? INT_MAX : INT_MIN;  // Return max/min on overflow
            return OVERFLOW;    
        }

        number = number * 10 + digit;
        index++;
        if (index == size)
        {
            break;
        }
        ch = str[index];
    }

    *pvalue = sign * number;
    if (index < size)
    {
        return INVALID;
    }

    return OK;
}

error string_to_int(const string *str, int *pvalue)
{
    return str_to_int(string_c_str(str), string_size(str), pvalue);
}

error string_view_to_int(const string_view *str_view, int *pvalue)
{
    return str_to_int(str_view->_c_str, str_view->_size, pvalue);
}