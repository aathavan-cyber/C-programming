#include <stdio.h>

#define ASCII 128

int main(void)
{
 int c, i, j;
 int freq[ASCII];

 for (i = 0; i < ASCII; ++i)
    freq[i] = 0;

 while ((c = getchar()) != EOF)
     if (c < ASCII)
        ++freq[c];

 for (i = 0; i < ASCII; ++i) {
     if (freq[i] > 0) {
         if (i == '\n')
            printf("\\n ");
         else if (i == '\t')
            printf("\\t ");
         else
            printf("%2c ", i);

         for (j = 0; j < freq[i]; ++j)
             putchar('*');
         putchar('\n');
     }
 }

 return 0;
}

