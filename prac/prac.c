#include <stdio.h>

int main()
{
    int a = 12;
    int *p = &a;
    p = (int *)12;
    // int b = (((int)(&a))+1);
    // printf("%p\n",&((((int)(&a))+1)));
    printf("%u\n",(*p+1));
}