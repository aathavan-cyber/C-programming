/*Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.*/

#include <stdio.h>
unsigned invert(unsigned x, int p, int n)
{
    x = x ^ (((1U << n) - 1) << (p - n + 1));
    return x;
}
int main(void)
{
    unsigned x = 204;
    int p = 0;
    int n = 2;
    
    unsigned result = invert(x, p, n);

    printf("Result = %u\n", result);

    return 0;
}
