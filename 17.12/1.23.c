/* ex1.23: a program to remove all comments from a C program*/
#include <stdio.h>

int main() {
    int c, prev = 0;
    int in_comment = 0;
    while ((c = getchar()) != EOF) {
        if (!in_comment && prev == '/' && c == '*') {
            in_comment = 1;
            prev = 0;
        } else if (in_comment && prev == '*' && c == '/') {
            in_comment = 0;
            prev = 0;
        } else if (!in_comment) {
            if (prev)
                putchar(prev);
            prev = c;
        } else {
            prev = c;
        }
    }
    return 0;
}

