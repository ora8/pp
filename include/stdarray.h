#pragma once


#define ARRAY_SIZE(x) sizeof(x) / sizeof(x[0])

#define ARRAY_CREATE(size, type) (type *)malloc((size) * sizeof(type))

#define ARRAY_RECREATE(array, new_size, type) (type *)realloc(array, (new_size) * sizeof(type))

#define ARRAY_COPY(dst, src, size, type) memcpy(dst, src, (size) * sizeof(type))

#define ARRAY_OVERLAP_COPY(dst, src, size, type) memmove(dst, src, (size) * sizeof(type))

#define ARRAY_COMPARE(arr1, size1, arr2, size2, type) \
    ((size1) == (size2) && (!memcmp(arr1, arr2, (size1) * sizeof(type))))
#define ARRAY_ZERO(array, size, type) memset(array, 0, size, sizeof(type));

#define CHAR_ARRAY_CREATE(size) (char *)malloc((size) * sizeof(char))

#define CHAR_ARRAY_RECREATE(array, new_size) (char *)realloc(array, (new_size) * sizeof(char))

#define CHAR_ARRAY_COPY(dst, src, size) memcpy(dst, src, (size) * sizeof(char))

#define CHAR_ARRAY_OVERLAP_COPY(dst, src, size) memmove(dst, src, (size) * sizeof(char))

#define CHAR_ARRAY_COMPARE(arr1, size1, arr2, size2) \
    ((size1) == (size2) && (!memcmp(arr1, arr2, (size1) * sizeof(char))))

#define CHAR_ARRAY_ZERO(array, size) memset(array, 0, (size) * sizeof(char));
