#include <stdio.h>

int main()
{
    int a[] = {1,2,3,4,5};
    int *x;
    printf("%p\n",a + 3);
    x = a;
    printf("%d\n",*a+3);
}