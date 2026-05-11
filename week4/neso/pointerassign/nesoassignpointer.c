#include <stdio.h>
int main()
{
    int a = 5;
    int *p = &a;
    int *q = p;
    *q = 10;
    printf("%d\n",*p);

}