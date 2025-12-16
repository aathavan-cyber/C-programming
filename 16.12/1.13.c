#include <stdio.h>

#define IN  1
#define OUT 0
#define MAXLEN 20 

int main(void)
{
 int c, state, len, i, j;
 int wl[MAXLEN + 1];

 state = OUT;
 len = 0;

 for (i = 0; i <= MAXLEN; ++i)
    wl[i] = 0;

 while ((c = getchar()) != EOF) {
     if (c == ' ' || c == '\n' || c == '\t') {
         if (state == IN) {
             if (len <= MAXLEN)
                ++wl[len];
             else
                ++wl[MAXLEN];
             len = 0;
             state = OUT;
         }
     }
     else {
         state = IN;
         ++len;
     }
 }

 for (i = 1; i <= MAXLEN; ++i) {
     printf("%2d | ", i);
      for (j = 0; j < wl[i]; ++j)
          putchar('*');
     putchar('\n');
 }

 return 0;
}

