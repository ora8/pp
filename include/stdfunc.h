#pragma once

#include <stdlib.h>

#include "stdstring.h"
#include "stdstring_view.h"
#include "stdvec.h"

void string_view_split(string_view_vec *vec, const char *str, char delimiter);
void string_view_split_str(string_view_vec *vec, const char *str, const char *delimiter);
void string_view_string_split(string_view_vec *vec, const string *str, char delimiter);
void string_view_string_split_str(string_view_vec *vec, const string *str, const char *delimiter);