/*Exercise 3-4. In a two's complement number representation, our version of itoa does not
handle the largest negative number, that is, the value of n equal to -(2wordsize-1). Explain why
not. Modify it to print that value correctly, regardless of the machine on which it runs.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

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

void itoa(int n, char s[])
{
    int i = 0;
    int sign = n;
    do {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main(void)
{
    char s[50];
    itoa(0, s);
    printf("0        -> %s\n", s);
    itoa(-1234, s);
    printf("-1234    -> %s\n", s);
    itoa(INT_MIN, s);
    printf("INT_MIN  -> %s\n", s);
    return 0;
}

