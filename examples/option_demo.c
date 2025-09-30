#include <stdio.h>

#include <stdopt.h>

int main() {
    // Test creating a opt_double with none
    opt_double *opt_none = opt_double_create_none();
    printf("opt_none is none: %s\n", opt_double_none(opt_none) ? "true" : "false");

    // Test creating a opt_double with a value
    opt_double *opt_some = opt_double_create(3.14);
    printf("opt_some is none: %s\n", opt_double_none(opt_some) ? "true" : "false");
    printf("opt_some value: %f\n", opt_double_some(opt_some));

    // Test has_some
    printf("opt_some has some: %s\n", opt_double_has_some(opt_some) ? "true" : "false");

    // Clean up
    opt_double_destroy(opt_none);
    opt_double_destroy(opt_some);

    // Test ptr_option with none
    opt_pchar optional_pointer;
    opt_pchar_set_none(&optional_pointer);

    printf("Size of optional pointer is %lu\n", sizeof(optional_pointer));

    opt_pchar_set_some(&optional_pointer, "Hello World!");
    printf("Opt pchar has value %s\n", opt_pchar_some(&optional_pointer));
    opt_pchar_set_none(&optional_pointer);
    printf("Opt pchar is none %s\n", opt_pchar_none(&optional_pointer) ? "true" : "false");

    return 0;
}