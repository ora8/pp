#include <stdio.h>

#include "stdstr.h"

int main() {
    // Create a small_str instance
    small_str *str = small_str_create("Hello");
    
    // Print the initial string and size
    printf("String: %s, Size: %d\n", small_str_c_str(str), small_str_size(str));

    // Push back a character
    small_str_push_back(str, '!');
    printf("After push_back: %s, Size: %d\n", small_str_c_str(str), small_str_size(str));

    // Pop back a character
    char poppedChar = small_str_pop_back(str);
    printf("Popped character: %c, After pop_back: %s, Size: %d\n", poppedChar, small_str_c_str(str), small_str_size(str));

    // Resize the string
    small_str_resize(str, 3);
    printf("After resize to 3: %s, Size: %d\n", small_str_c_str(str), small_str_size(str));

    // Set a character at a specific index
    small_str_set(str, 1, 'a');
    printf("After set at index 1: %s, Size: %d\n", small_str_c_str(str), small_str_size(str));

    // Insert a character at index 0
    small_str_insert(str, 0, 'X');
    printf("After insert 'X' at index 0: %s, Size: %d\n", small_str_c_str(str), small_str_size(str));

    // Remove a character at index 2
    small_str_remove(str, 2);
    printf("After remove at index 2: %s, Size: %d\n", small_str_c_str(str), small_str_size(str));

    // Find a character
    int index = small_str_find(str, 'a');
    printf("Index of 'a': %d\n", index);

    // Clear the string
    small_str_clear(str);
    printf("After clear: %s, Size: %d\n", small_str_c_str(str), small_str_size(str));

    // Destroy the small_str instance
    small_str_destroy(str);

    return 0;
}
