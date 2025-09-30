#include <stdconv.h>
#include <stderr.h>
#include <stdio.h>
#include <stdstring_view.h>

void parse_string_view(string_view *str_view)
{
       int value;
    error err = string_view_to_int(str_view, &value);
    if (!err)
        printf("Parsed integer: %d\n", value);
    else
        printf("String %s gives error %d\n", str_view->_c_str, err);
}

int main() {

    printf("int size %lu\n", sizeof(int));

    const char input[] = "   -12345";
    string_view str_view;
    string_view_init(&str_view, input, 9);
    parse_string_view(&str_view);
 
    const char input2[] = "  23134135345243562346gre994499";
    string_view_init(&str_view, input2, 31);
    parse_string_view(&str_view);

    const char input3[] = "  234135as2223";
    string_view_init(&str_view, input3, 14);

    parse_string_view(&str_view);

    return 0;
}
