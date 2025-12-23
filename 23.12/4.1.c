/*Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost
occurrence of t in s, or -1 if there is none.*/
#include <stdio.h>

int strindex(char s[], char t[])
{
    int i, j, k;
    int pos = -1;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0;
             t[k] != '\0' && s[j] == t[k];
             j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            pos = i;   
    }
    return pos;
}

int main(void)
{
    char s[] = "this is a test, this is only a test";
    char t[] = "test";

    int index = strindex(s, t);
    printf("Rightmost index: %d\n", index);

    return 0;
}

