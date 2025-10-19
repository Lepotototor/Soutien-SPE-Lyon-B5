#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <stdio.h>

#include "../src/str_to_upper.h"

TestSuite(str_to_upper);

Test(str_to_upper, basic_test1, .timeout = 5)
{
    char str[] = "Who is the end ? \tI'm here";
    char res[] = "WHO IS THE END ? \tI'M HERE";
    char *got = str_to_upper(str);

    cr_expect(eq(str, res, got), "Expected: \"%s\"\nGot: \"%s\"", res, got);
    free(got);
}

Test(str_to_upper, basic_test2, .timeout = 5)
{
    char str[] = "Who is the best BDE ? It's Pycolo of course";
    char res[] = "WHO IS THE BEST BDE ? IT'S PYCOLO OF COURSE";
    char *got = str_to_upper(str);

    cr_expect(eq(str, res, got), "Expected: \"%s\"\nGot: \"%s\"", res, got);
    free(got);
}

Test(str_to_upper, basic_test3, .timeout = 5)
{
    char str[] = "My fav things is evalexpr";
    char res[] = "MY FAV THINGS IS EVALEXPR";
    char *got = str_to_upper(str);

    cr_expect(eq(str, res, got), "Expected: \"%s\"\nGot: \"%s\"", res, got);
    free(got);
}

Test(str_to_upper, basic_test4, .timeout = 5)
{
    char str[] = "Wyatt is the most beautiful";
    char res[] = "WYATT IS THE MOST BEAUTIFUL";
    char *got = str_to_upper(str);

    cr_expect(eq(str, res, got), "Expected: \"%s\"\nGot: \"%s\"", res, got);
    free(got);
}

Test(str_to_upper, all_lower, .timeout = 5)
{
    char str[] = "wyatt is the most beautiful";
    char res[] = "WYATT IS THE MOST BEAUTIFUL";
    char *got = str_to_upper(str);

    cr_expect(eq(str, res, got), "Expected: \"%s\"\nGot: \"%s\"", res, got);
    free(got);
}

Test(str_to_upper, all_upper, .timeout = 5)
{
    char str[] = "WHY GOUSSOT DOESNT LIKE PYCOLO";
    char *got = str_to_upper(str);

    cr_expect(eq(str, str, got), "Expected: \"%s\"\nGot: \"%s\"", str, got);
    free(got);
}

Test(str_to_upper, empty_test, .timeout = 5)
{
    char str1[] = "";
    char result[] = "";
    char *got = str_to_upper(str1);

    cr_expect(eq(str, result, got), "Expected: \"%s\"\nGot: \"%s\"", result,
              got);
    free(got);
}

Test(str_to_upper, null_test, .timeout = 5)
{
    char *null = NULL;
    char *got = str_to_upper(null);

    cr_expect(eq(ptr, null, got), "Expected NULL got a string");
}
