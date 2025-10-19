#ifndef RESIZE_MAT_H
#define RESIZE_MAT_H

#include <stddef.h>

struct tab
{
    int *data;
    size_t size;
};

struct tab *resize_tab(struct tab *tab, size_t new_size);

struct tab *sub_tab(const struct tab *tab, size_t new_size);

#endif /* ! RESIZE_MAT_H */
