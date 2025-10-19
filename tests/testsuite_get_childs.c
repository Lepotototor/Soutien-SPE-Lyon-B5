#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <stdio.h>

#include "../src/get_childs.h"

static int is_sorted(const int *arr, size_t size)
{
    for (size_t i = 1; i < size; i++)
        if (arr[i - 1] > arr[i])
            return 0;
    return 1;
}

TestSuite(get_childs);

Test(get_childs, basic_test1, .timeout = 5)
{
    FILE *null_out = fopen("/dev/null", "w");
    FILE *old_stdout = stdout;
    stdout = null_out;

    int *got = get_childs(3);

    stdout = old_stdout;
    fclose(null_out);

    cr_expect_neq(NULL, got, "Expected an array got NULL");

    cr_expect_eq(1, is_sorted(got, 3), "PIDs are not sorted");
    free(got);
}

Test(get_childs, basic_test2, .timeout = 5)
{
    FILE *null_out = fopen("/dev/null", "w");
    FILE *old_stdout = stdout;
    stdout = null_out;

    int *got = get_childs(12);

    stdout = old_stdout;
    fclose(null_out);

    cr_expect_neq(NULL, got, "Expected an array got NULL");

    cr_expect_eq(1, is_sorted(got, 12), "PIDs are not sorted");
    free(got);
}

Test(get_childs, big_test, .timeout = 5)
{
    FILE *null_out = fopen("/dev/null", "w");
    FILE *old_stdout = stdout;
    stdout = null_out;

    int *got = get_childs(100);

    stdout = old_stdout;
    fclose(null_out);

    cr_expect_neq(NULL, got, "Expected an array got NULL");

    cr_expect_eq(1, is_sorted(got, 100), "PIDs are not sorted");
    free(got);
}

Test(get_childs, null_test, .timeout = 5)
{
    int *got = get_childs(0);

    cr_expect(eq(ptr, NULL, got), "Expected nothing but got an array");
}
