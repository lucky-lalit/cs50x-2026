#include <stdio.h>

int main()
{
 int a[] = {5,10,15,20,25,30,25,40};
 int *ptr = &(a[2]);
 printf("%d\n",*(ptr--));
 printf("%d\n",*ptr);   
}
