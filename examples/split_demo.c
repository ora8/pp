#include <stdfunc.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char buf[128];
    const char *text = "apple,banana,cherry,peach";
    char delimiter1 = ',';
    const char *delimiter2 = ",b";

    string_view_vec vec1;
    string_view_vec_init(&vec1);
    string_view_split(&vec1, text, delimiter1);

    printf("Split using single character delimiter '%c':\n", delimiter1);
    for (size_t i = 0; i < string_view_vec_size(&vec1); i++)
    {
        string_view sv = string_view_vec_get(&vec1, i);
        strncpy(buf, string_view_c_str(&sv), string_view_size(&sv));
        buf[string_view_size(&sv)] = '\0';
        printf("  [%zu]: '%s' (size: %zu)\n", i, buf, string_view_size(&sv));
    }
    string_view_vec_finit(&vec1);

    string_view_vec vec2;
    string_view_vec_init(&vec2);
    string_view_split_str(&vec2, text, delimiter2);

    printf("\nSplit using multi-character delimiter \"%s\":\n", delimiter2);
    for (size_t i = 0; i < string_view_vec_size(&vec2); i++)
    {
        string_view sv = string_view_vec_get(&vec2, i);
        strncpy(buf, string_view_c_str(&sv), string_view_size(&sv));
        buf[string_view_size(&sv)] = '\0';
        printf("  [%zu]: '%s' (size: %zu)\n", i, buf, string_view_size(&sv));
    }
    string_view_vec_finit(&vec2);

    return 0;
}

