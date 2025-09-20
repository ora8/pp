#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdstring.h>

int main()
{
    string *s1 = string_create("Hello World");
    string *s2 = string_create(". This is a beautiful world!");
    string *s3 = string_create(" Yes it is!!");

    printf("s1: %s\n", string_c_str(s1));

    printf("s2: %s\n", string_c_str(s2));

    printf("s3: %s\n", string_c_str(s3));

    string_concat(s1, s2);
    printf("Concatenated, s1, s2: %s\n", string_c_str(s1));

    string_concat(s2, s3);
    printf("Concatenated, s2, s3: %s\n", string_c_str(s2));

    string_concat(s1, s2);
    printf("Concatenated, s1, s2: %s\n", string_c_str(s1));

    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create("HelWorld!");
    printf("Created, s1: %s\n", string_c_str(s1));

    string_insert_str(s1, 3, "lo ");
    printf("Inserted, s1: %s\n", string_c_str(s1));

    s2 = string_create("This would be a beautful world without the these politicians!");
    printf("Created, s2: %s\n", string_c_str(s2));

    string_insert_str(s2, 21, "i");
    printf("Inserted, s2: %s\n", string_c_str(s2));

    string_insert_str(s2, 31, ", I do not enumerate the persons,");
    printf("Inserted, s2: %s\n", string_c_str(s2));

    return 0;
}