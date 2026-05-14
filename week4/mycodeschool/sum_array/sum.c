#include <stdio.h>
#include <stdlib.h>

int sum(int a[],int len)
{   int summation = 0;
    int *p = a;
    printf("%d\n",sizeof(a));
    for (int i = 0; i < len; i++)
    {  
//           printf("%d\n",a[i]);
        // printf("%d: %d\n",i,(*p+i));
        summation += *(p+i);
    }
    return summation;

}

int main()
{
    int arr1[100];
    int *arr2 = malloc(100 * sizeof(int));
    printf("%d\n",sizeof(arr1));
    printf("%d\n",sizeof(arr2));
    int b[] = {1,2,3,4,5};
    printf("%d\n",sizeof(b));
    int len = sizeof(b)/sizeof(b[0]);
    int total = sum(b,len);
    printf("sum of array a is %d\n",total);
}