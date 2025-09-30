#pragma once

#include "stderr.h"
#include "stdstring.h"
#include "stdstring_view.h"

error string_to_int(const string *str, int *pvalue);
error string_view_to_int(const string_view *str_view, int *pvalue);