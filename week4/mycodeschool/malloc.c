#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    int *a = malloc(n*sizeof(int));
    for (int i = 0;i < n; i ++)
    {
        a[i] = i + 1;

    }
    for(int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }

}