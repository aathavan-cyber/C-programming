// Exercise 4-14. Define a macro swap(t,x,y) that interchanges two arguments of type t.
#include<stdio.h>
#define swap(t,a,b) { t temp = a; a = b; b = temp; }

int main()
{
    int a = 10;
    int b = 5;
    swap(int, a, b);
    printf("After swapping integers: a = %d, b = %d\n", a, b);
    double x = 7.6;
    double y = 5.4;
    swap(double, x, y);
    printf("After swapping doubles: x = %.2f, y = %.2f\n", x, y);
    return 0;
}
