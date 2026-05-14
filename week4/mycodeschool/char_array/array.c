#include <stdio.h>

void print(int a[],int len)
{
    
    for (int i = 0; i < len ; i++)
    {
        printf("%d ",*a);
        a = a + 1;
    }
}

int main()
{
    int a[] = {1,2,3,4,5};
    int len = sizeof(a)/sizeof(a[0]);
    print(a,len);
}