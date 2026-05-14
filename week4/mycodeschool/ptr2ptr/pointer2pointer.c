#include <stdio.h>

int main()
{
int a = 5;
// printf("%d\n",&a);
int *p;
p = &a;
*p = 7;
int **q;
q = &p;
printf("%d\n",p);
printf("%d\n",*q);
int ***r;
r = &q;
printf("%d\n",***r);
}