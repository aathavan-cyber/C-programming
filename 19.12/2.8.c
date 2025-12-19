/*Ex2.8:Write a function rightrot(x,n) that returns the value of the integer x rotated
to the right by n positions.*/
#include <stdio.h>

unsigned rightrot(unsigned x, int n)
{
    int i;
    unsigned last_bit;
    for (i = 0; i < n; i++)
    {
        last_bit = x & 1;       
        x = x >> 1;        
        x = x | (last_bit << 31); 
    }
    return x;
}

int main(void)
{
    unsigned x = 22;   
    int n = 2;

    unsigned result = rightrot(x, n);

    printf("%u\n", result);

    return 0;
}
