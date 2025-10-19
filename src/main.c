#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array_even.h"
#include "get_childs.h"
#include "merge_blocks.h"
#include "resize_tab.h"
#include "str_to_upper.h"

void test_merge_blocks(void)
{
    char str1[] = "I Love ";
    char str2[] = "Dragons";
    char *res = merge_blocks(str1, strlen(str1), str2, strlen(str2) + 1);
    printf("Merging \"%s\"  and  \"%s\"\n", str1, str2);
    printf("Got: \"%s\"\n\n", res);
    free(res);

    char str3[] = "Are they numbers ?? ";
    unsigned char tab[] = { 35, 37, 38, 39, 40, 41, 42, 43, 44, 0 };
    char str4[] = "{ 35, 37, 38, 39, 40, 41, 42,43,44,0}";
    res = merge_blocks(str3, strlen(str3), tab, sizeof(tab));
    printf("Merging \"%s\"  and  \"%s\"\n", str3, str4);
    printf("Got: \"%s\"\n\n", res);
    free(res);
}

void test_get_childs(void)
{
    size_t n = 5;
    int *res = get_childs(n);
    if (res == NULL)
    {
        puts("No child");
        return;
    }

    putchar('\n');

    for (size_t i = 0; i < n; i++)
        printf("%i ", res[i]);
    putchar('\n');
    putchar('\n');

    free(res);
}

void test_str_to_upper(void)
{
    char str1[] = "I love dragons";
    char str2[] = "but I prefer my asm";
    char str3[] = "THIS ONE WILL NOT CHANGE";

    char *res = str_to_upper(str1);
    printf("str_to_upper(\"%s\") = %s\n", str1, res);
    free(res);

    res = str_to_upper(str2);
    printf("str_to_upper(\"%s\") = %s\n", str2, res);
    free(res);

    res = str_to_upper(str3);
    printf("str_to_upper(\"%s\") = %s\n", str3, res);
    free(res);

    putchar('\n');
}

void test_array_even(void)
{
    int tab1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    int *res = NULL;
    size_t size = array_even(tab1, sizeof(tab1) / sizeof(int), &res);
    for (size_t i = 0; i < size; i++)
        printf("%i ", res[i]);
    printf("\nSize: %zu\n\n", size);
    free(res);

    int tab2[] = { 1, 13, 59, 43, 55, 7 };
    res = NULL;
    size = array_even(tab2, sizeof(tab2) / sizeof(int), &res);
    if (res == NULL)
        puts("Array is NULL");
    else
        free(res);
    if (size == 0)
        puts("Size is NULL");

    putchar('\n');
}

void test_resize_tab()
{
    struct tab *tab = malloc(sizeof(struct tab));
    if (tab == NULL)
        return;
    tab->data = calloc(7, sizeof(int));
    if (tab->data == NULL)
    {
        free(tab);
        return;
    }

    tab->size = 7;
    int arr[] = { 45, 67, 89, 12, 4, 42, -1 };

    printf("Initial tab: ");
    for (size_t i = 0; i < 7; i++)
    {
        tab->data[i] = arr[i];
        printf("%i ", arr[i]);
    }
    putchar('\n');

    tab = resize_tab(tab, 5);

    printf("Resize to 5 tab: ");
    for (size_t i = 0; i < 5; i++)
        printf("%i ", arr[i]);
    putchar('\n');

    tab = resize_tab(tab, 0);
    if (tab)
    {
        if (tab->data)
            free(tab->data);
        free(tab);
        puts("Tab should be bfreed");
    }
    else
        puts("Tab is freed");
}

#ifndef DEBUG
int main(void)
{
#    ifdef MERGE_BLOCKS
    test_merge_blocks();
#    endif

#    ifdef GET_CHILDS
    test_get_childs();
#    endif

#    ifdef ARRAY_EVEN
    test_array_even();
#    endif

#    ifdef STR_TO_UPPER
    test_str_to_upper();
#    endif

#    ifdef RESIZE_TAB
    test_resize_tab();
#    endif



/*


            You can add tests in the main function here


  */
}
#endif
