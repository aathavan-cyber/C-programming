/* ex2.2: a loop equivalent to the for loop without using && or ||. */
#include <stdio.h>

#define MAXLINE 1000

int main(void) {
    char s[MAXLINE];
    int i, c;
    for (i = 0; i < MAXLINE - 1; i++) {
        c = getchar();
        if (c == EOF)
            break;
        if (c == '\n')
            break;
        s[i] = c;
    }
    s[i] = '\0';
    printf("Line read: %s\n", s);
    return 0;
}

