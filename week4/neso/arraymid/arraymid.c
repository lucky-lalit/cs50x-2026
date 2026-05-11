#include <stdio.h>

// int mid(int a[], int n);

int *mid(int a[], int n)
{
    return &a[n/2];
}

int main()
{
    int a[] = {1,2,3,4,5};
    int n = sizeof(a)/sizeof(a[0]);
    int *ptr = mid(a,n);
    printf("%d\n",*ptr);
    return 0;
}

// int *mid(int a[], int n)
// {
//     return &a[n/2];
// }