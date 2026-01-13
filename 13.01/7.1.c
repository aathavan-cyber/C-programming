/*Exercise 7-1. Write a program that converts upper case to lower or lower case to upper,
depending on the name it is invoked with, as found in argv[0].*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(int argc, char *argv[])
{
    int lower = 0;
    int c;

    if (strstr(argv[0], "lower") != NULL)
    {
        lower = 1;
    }

    while ((c = getchar()) != EOF)
    {
        if (lower)
        {
            putchar(tolower(c));
        }
        else
        {
            putchar(toupper(c));
        }
    }

    return 0;
}
