/* ex1.20: a program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns*/

#include <stdio.h>
#define TABSTOP 8

int main() {
    int c, col = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            int spaces = TABSTOP - (col % TABSTOP);
            while (spaces--) {
                putchar(' ');
                col++;
            }
        } else {
            putchar(c);
            col++;
            if (c == '\n')
                col = 0;
        }
    }
    return 0;
}

