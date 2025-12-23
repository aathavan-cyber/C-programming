/*Exercise 3-6. Write a version of itoa that accepts three arguments instead of two. The third
argument is a minimum field width; the converted number must be padded with blanks on the
left if necessary to make it wide enough.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char s[])
{
    int i, j;
    char temp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void itoa_width(int n, char s[], int width)
{
    int i = 0;
    int sign = n;
    do {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);
    if (sign < 0)
        s[i++] = '-';
    while (i < width)
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}

int main(void)
{
    char s[50];
    itoa_width(123, s, 6);
    printf("123 width 6  -> \"%s\"\n", s);
    itoa_width(-45, s, 5);
    printf("-45 width 5  -> \"%s\"\n", s);
    itoa_width(9999, s, 2);
    printf("9999 width 2 -> \"%s\"\n", s);
    return 0;
}

