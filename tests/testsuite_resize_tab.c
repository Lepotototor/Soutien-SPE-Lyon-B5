#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <stdio.h>

#include "../src/resize_tab.h"

static void print_array(const int *arr, size_t size, char *buf, size_t buf_size)
{
    size_t len = 0;
    len += snprintf(buf + len, buf_size - len, "[");
    for (size_t i = 0; i < size && len < buf_size - 1; ++i)
    {
        len += snprintf(buf + len, buf_size - len, "%d", arr[i]);
        if (i < size - 1)
            len += snprintf(buf + len, buf_size - len, ", ");
    }
    snprintf(buf + len, buf_size - len, "]");
}

TestSuite(resize_tab);

static struct tab *init_tab(int *arr, size_t size)
{
    struct tab *tab = malloc(sizeof(struct tab));
    tab->size = size;
    tab->data = calloc(tab->size, sizeof(int));

    for (size_t i = 0; i < size; i++)
        tab->data[i] = arr[i];

    return tab;
}

Test(resize_tab, basic_test1, .timeout = 5)
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    struct tab *tab = init_tab(arr, sizeof(arr) / sizeof(int));

    int expected[] = { 1, 2, 3, 4, 5 };
    resize_tab(tab, 5);

    char exp_buf[128], got_buf[128];
    print_array(expected, 5, exp_buf, sizeof(exp_buf));
    print_array(tab->data, tab->size, got_buf, sizeof(got_buf));

    cr_expect_eq(5, tab->size, "Expected size %i, got %zu", 5, tab->size);
    cr_expect_arr_eq(expected, tab->data, 5,
                     "Returned array is not good\nExpected: %s\nGot: %s\n",
                     exp_buf, got_buf);

    free(tab->data);
    free(tab);
}

Test(resize_tab, basic_test2, .timeout = 5)
{
    int arr[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 12, 34, 1, 2,
                  8, 6, 3, 5, 7, 9, 3, 4, 5, 1, 2, 4,  5,  7, 8 };
    struct tab *tab = init_tab(arr, sizeof(arr) / sizeof(int));

    int expected[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    resize_tab(tab, 10);

    char exp_buf[128], got_buf[128];
    print_array(expected, 10, exp_buf, sizeof(exp_buf));
    print_array(tab->data, tab->size, got_buf, sizeof(got_buf));

    cr_expect_eq(10, tab->size, "Expected size %i, got %zu", 10, tab->size);
    cr_expect_arr_eq(expected, tab->data, 10,
                     "Returned array is not good\nExpected: %s\nGot: %s\n",
                     exp_buf, got_buf);

    free(tab->data);
    free(tab);
}

Test(resize_tab, size_zero, .timeout = 5)
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    struct tab *tab = init_tab(arr, sizeof(arr) / sizeof(int));

    struct tab *res = resize_tab(tab, 0);

    cr_expect_eq(NULL, res, "Expected NULL");
}

Test(resize_tab, same_size, .timeout = 5)
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    struct tab *tab = init_tab(arr, sizeof(arr) / sizeof(int));

    resize_tab(tab, tab->size);

    char exp_buf[128], got_buf[128];
    print_array(arr, 10, exp_buf, sizeof(exp_buf));
    print_array(tab->data, tab->size, got_buf, sizeof(got_buf));

    cr_expect_eq(tab->size, sizeof(arr) / sizeof(int),
                 "Expected size %zu, got %zu", sizeof(arr) / sizeof(int),
                 tab->size);
    cr_expect_arr_eq(arr, tab->data, tab->size,
                     "Returned array is not good \nExpected: %s\nGot: %s\n",
                     exp_buf, got_buf);

    free(tab->data);
    free(tab);
}

Test(resize_tab, greater_size, .timeout = 5)
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    struct tab *tab = init_tab(arr, sizeof(arr) / sizeof(int));

    resize_tab(tab, tab->size + 42);

    char exp_buf[128], got_buf[128];
    print_array(arr, 10, exp_buf, sizeof(exp_buf));
    print_array(tab->data, tab->size, got_buf, sizeof(got_buf));

    cr_expect_eq(tab->size, tab->size, "Expected size %zu, got %zu", tab->size,
                 tab->size);
    cr_expect_arr_eq(arr, tab->data, tab->size,
                     "Returned array is not good\nExpected: %s\nGot: %s\n",
                     exp_buf, got_buf);

    free(tab->data);
    free(tab);
}
Test(resize_tab, empty_test, .timeout = 5)
{
    struct tab *tab = malloc(sizeof(struct tab));
    tab->data = NULL;
    tab->size = 0;
    resize_tab(tab, 0);

    cr_expect_eq(0, tab->size, "Expected size 0, got %zu", tab->size);
    cr_expect_eq(NULL, tab->data, "Expected NULL got an array");

    free(tab);
}

Test(resize_tab, null_test, .timeout = 5)
{
    struct tab *null = NULL;
    struct tab *res = NULL;
    res = resize_tab(null, 0);

    cr_expect_eq(NULL, res, "Expected NULL got an array");
}
