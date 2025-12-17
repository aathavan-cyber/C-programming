/* ex1.22: a program to ``fold'' long input lines into two or more shorter lines after
the last non-blank character that occurs before the n-th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column.*/
#include <stdio.h>
#define MAXCOL 40

int main() {
    int c, col = 0, last_space = -1;
    char line[1000];
    int i = 0;
    while ((c = getchar()) != EOF) {
        line[i++] = c;
        col++;
        if (c == ' ')
            last_space = i - 1;
        if (col >= MAXCOL) {
            if (last_space != -1) {
                line[last_space] = '\n';
                col = i - last_space - 1;
                last_space = -1;
            }
        }
        if (c == '\n') {
            col = 0;
            last_space = -1;
        }
        if (i >= 999) {
            line[i] = '\0';
            printf("%s", line);
            i = 0;
        }
    }
    line[i] = '\0';
    printf("%s", line);
    return 0;
}

