#include "merge_blocks.h"

#include <malloc.h>
#include <string.h>

/*
    Merge blocks take two pointers to void * and the size for each block
    It should return a new pointer dynamically allocated to a new memory area
    The returned pointer has data from the two given pointer

    Example: merge_blocks("Hello ", 6, "World", 5) give a pointer to "Hello
   World"

    if b1 is NULL you should return a pointer with the same data as b2
    if b2 is NULL you should return a pointer with the same data as b1
    if b1 and b2 are NULL the function should return NULL

    if any error occur the function should return NULL
*/

void *merge_blocks(void *b1, size_t s1, void *b2, size_t s2)
{
    (void)b1;
    (void)b2;
    (void)s1;
    (void)s2;
    return NULL;
}
