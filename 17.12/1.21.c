/* ex1.21:a program entab that replaces strings of blanks by the minimum
number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. */
#include <stdio.h>
#define TABSTOP 8

int main() {
    int c, space = 0, col = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            space++;
            col++;
            if (col % TABSTOP == 0) {
                putchar('\t');
                space = 0;
            }
        } else {
            while (space > 0) {
                putchar(' ');
                space--;
            }
            putchar(c);
            if (c == '\n')
                col = 0;
            else
                col++;
        }
    }
    return 0;
}

