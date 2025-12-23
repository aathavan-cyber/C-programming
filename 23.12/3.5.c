/*Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into a base b
character representation in the string s. In particular, itob(n,s,16) formats s as a
hexadecimal integer in s.*/
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

void itob(int n, char s[], int b)
{
    int i = 0;
    int sign = n;
    int digit;
    if (b < 2 || b > 16) {
        s[0] = '\0';
        return;
    }
    do {
        digit = abs(n % b);
        s[i++] = (digit < 10) ? digit + '0' : digit - 10 + 'A';
    } while ((n /= b) != 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main(void)
{
    char s[50];
    itob(255, s, 2);
    printf("255 base 2  -> %s\n", s);
    itob(255, s, 8);
    printf("255 base 8  -> %s\n", s);
    itob(255, s, 16);
    printf("255 base 16 -> %s\n", s);
    itob(-31, s, 16);
    printf("-31 base 16 -> %s\n", s);
    return 0;
}

