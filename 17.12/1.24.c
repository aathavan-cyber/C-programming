/* ex1.24: a program to check a C program for rudimentary syntax errors like
unmatched parentheses, brackets and braces.*/
#include <stdio.h>

int main() {
    int c;
    int paren = 0, brace = 0, bracket = 0;
    while ((c = getchar()) != EOF) {
        if (c == '(') paren++;
        if (c == ')') paren--;
        if (c == '{') brace++;
        if (c == '}') brace--;
        if (c == '[') bracket++;
        if (c == ']') bracket--;
    }
    if (paren != 0)
        printf("Unmatched parentheses\n");
    if (brace != 0)
        printf("Unmatched braces\n");
    if (bracket != 0)
        printf("Unmatched brackets\n");
    return 0;
}

