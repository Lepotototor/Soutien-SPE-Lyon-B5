#include "get_childs.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/*
    get_childs function should return a dynamically allocated array with n PIDs
    you should create a dynamic int array and create n childs
    Each child will print "I'm the child number <num>, my pid is <pid>"
    The array should contain all childs pid in the order of creation

    Do not take care pid number, it will always be different,
    they just need to be order and greater than father pid

    Example: get_childs(4) = { 7060, 7061, 7064, 7065 };
    I'm the child number 1, my pid is 7060
    I'm the child number 2, my pid is 7061
    I'm the child number 3, my pid is 7064
    I'm the child number 4, my pid is 7065

    if any error occur the function should return NULL

    do not forget to get the terminaison of childs

*/

int *get_childs(size_t n)
{
    (void)n;
    return NULL;
}
