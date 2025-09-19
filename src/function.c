#include <string.h>

#include "function.h"

void string_view_split_1(string_view_vec *vec, const char *str, char delimiter)
{
    size_t start = 0;
    size_t len = strlen(str);
    for (size_t i = 0; i <= len; i++)
    {
        if (str[i] == delimiter || str[i] == '\0')
        {
            string_view *sv = string_view_create(&str[start], i - start);
            string_view_vec_push_back(vec, sv);

            start = i + 1;
        }
    }
}
void string_view_split_2(string_view_vec *vec, const char *str, const char *delimiter)
{
    size_t start = 0;
    size_t len = strlen(str);
    size_t delim_len = strlen(delimiter);
    for (size_t i = 0; i <= len - delim_len;)
    {
        if (strncmp(&str[i], delimiter, delim_len) == 0)
        {
            string_view *sv = string_view_create(&str[start], i - start);
            string_view_vec_push_back(vec, sv);

            start = i + delim_len;
            i += delim_len;
        }
        else
        {
            i++;
        }
    }
    // Add the last segment
    if (start <= len)
    {
        string_view *sv = string_view_create(&str[start], len - start);
        string_view_vec_push_back(vec, sv);
    }
}
void string_view_string_split_1(string_view_vec *vec, const string *str, char delimiter)
{
    string_view_split_1(vec, string_c_str(str), delimiter);
}

void string_view_string_split_2(string_view_vec *vec, const string *str, const char *delimiter)
{
    string_view_split_2(vec, string_c_str(str), delimiter);
}