#include "resize_tab.h"

#include <malloc.h>

/*
    For this Exercise you need to use the struct tab given in the header
    for resize_tab you will have a struct tab given and a new size for this one

    you should reduce the struct tab to the given size
    if the new size is equal or bigger to actual do nothing and return tab

    you should realloc the field data in the struct to the new size
    do not care for memory loss


    Example:
        struct tab tab = { { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, 9 };
        resize_tab(&tab, 4);
        print(tab)
        >>> { 1, 2, 3, 4 }   Size: 4


    if any error occur you should return NULL
*/

struct tab *resize_tab(struct tab *tab, size_t new_size)
{}

/*
    Same as previous but you can't modify the struct
    you should return a new struct with the sub tab

    Example:
        struct tab tab = { { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, 9 };
        struct *new_tab = resize_tab(&tab, 4);

        print(tab)
        >>> { 1, 2, 3, 4, 5, 6, 7, 8, 9 }   Size: 9
        print(new_tab)
        >>> { 1, 2, 3, 4 }   Size: 4


    if the new size is equal or bigger then the older you shoudl copy the entire
   data field in the new struct
*/

struct tab *sub_tab(const struct tab *tab, size_t new_size)
{}
