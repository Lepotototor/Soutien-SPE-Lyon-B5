#include "str_to_upper.h"

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE 64

/*
    str_to_upper return a dynamic allocated pointer to new a string
    all lowcases char of str should be converted in upper case in the returned
   string

    you need to use fork and a pipe !!
    the child process will convert the string to an upper string and write it
   using the pipe
   the father will allocate the memory, read the new string from
   the pipe and puts it into the allocated pointer and return it

    Example:  str_to_upper("Hello World") = "HELLO WORLD"

    if any error occur your should return -1
*/

char *str_to_upper(const char *s)
{}
