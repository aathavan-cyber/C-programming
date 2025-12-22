/*Exercise 3-1. Our binary search makes two tests inside the loop, when one would suffice (at
the price of more tests outside.) Write a version with only one test inside the loop and
measure the difference in run-time.*/
#include <stdio.h>

int binsearch(int x, int v[], int n);

int main(void)
{
    int v[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(v) / sizeof(v[0]);
    printf("Index of 7: %d\n", binsearch(7, v, n));
    printf("Index of 4: %d\n", binsearch(4, v, n));
    return 0;
}

int binsearch(int x, int v[], int n)
{
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x <= v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (low < n && v[low] == x)
        return low;
    else
        return -1;
}

