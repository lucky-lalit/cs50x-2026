#include <stdio.h>

void increment(int *x)
{
    *x = *x + 1;
}

int main()
{
    int a = 10;
    increment(&a);
    // printf("%d\n",increment(a));
    printf("%d\n",a);
}