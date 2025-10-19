#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <stdio.h>

#include "../src/resize_tab.h"

TestSuite(sub_tab);

static struct tab *init_tab(int *arr, size_t size)
{
    struct tab *tab = malloc(sizeof(struct tab));
    tab->size = size;
    tab->data = calloc(tab->size, sizeof(int));

    for (size_t i = 0; i < size; i++)
        tab->data[i] = arr[i];

    return tab;
}

Test(sub_tab, basic_test1, .timeout = 5)
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    struct tab *tab = init_tab(arr, sizeof(arr) / sizeof(int));

    struct tab *res = NULL;
    int expected[] = { 1, 2, 3, 4, 5 };

    res = sub_tab(tab, 5);

    cr_expect_neq(NULL, res, "Expected an array got NULL");
    cr_expect_eq(5, res->size, "Expected size %i, got %zu", 5, tab->size);
    cr_expect_arr_eq(expected, res->data, 5, "Returned array is not good");

    free(tab->data);
    free(tab);
    free(res->data);
    free(res);
}

Test(sub_tab, basic_test2, .timeout = 5)
{
    int arr[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 12, 34, 1, 2,
                  8, 6, 3, 5, 7, 9, 3, 4, 5, 1, 2, 4,  5,  7, 8 };
    struct tab *tab = init_tab(arr, sizeof(arr) / sizeof(int));

    int expected[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    struct tab *res = NULL;

    res = sub_tab(tab, 10);

    cr_expect_neq(NULL, res, "Expected an array got NULL");
    cr_expect_eq(10, res->size, "Expected size %i, got %zu", 10, tab->size);
    cr_expect_arr_eq(expected, res->data, 10, "Returned array is not good");

    free(tab->data);
    free(tab);
    free(res->data);
    free(res);
}

Test(sub_tab, size_zero, .timeout = 5)
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    struct tab *tab = init_tab(arr, sizeof(arr) / sizeof(int));

    struct tab *res = sub_tab(tab, 0);

    cr_expect_eq(NULL, res, "Expected NULL");
}

Test(sub_tab, same_size, .timeout = 5)
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    struct tab *tab = init_tab(arr, sizeof(arr) / sizeof(int));

    sub_tab(tab, tab->size);

    cr_expect_eq(tab->size, tab->size, "Expected size %zu, got %zu", tab->size,
                 tab->size);
    cr_expect_arr_eq(arr, tab->data, tab->size, "Returned array is not good");

    free(tab->data);
    free(tab);
}

Test(sub_tab, greater_size, .timeout = 5)
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    struct tab *tab = init_tab(arr, sizeof(arr) / sizeof(int));

    sub_tab(tab, tab->size + 42);

    cr_expect_eq(tab->size, tab->size, "Expected size %zu, got %zu", tab->size,
                 tab->size);
    cr_expect_arr_eq(arr, tab->data, tab->size, "Returned array is not good");

    free(tab->data);
    free(tab);
}
Test(sub_tab, empty_test, .timeout = 5)
{
    struct tab *tab = malloc(sizeof(struct tab));
    tab->data = NULL;
    tab->size = 0;
    struct tab *res = NULL;
    res = sub_tab(tab, 0);

    cr_expect_eq(NULL, res, "Expected NULL got an array");

    free(tab);
}

Test(sub_tab, null_test, .timeout = 5)
{
    struct tab *null = NULL;
    struct tab *res = NULL;
    res = sub_tab(null, 0);

    cr_expect_eq(NULL, res, "Expected NULL got an array");
}
