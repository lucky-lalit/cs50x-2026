#include <stdio.h>
#include <stdlib.h>

int compare(int a, int b)
{
    if (a > b) return -1;
    return 1;
}

// int absolute_compare(int a,int b)
// {
//     if(abs(a) > abs(b)) return 1;
//     return -1;
// }

void bubblesort(int a[],int n,int(*compare)(int,int))
{
    int i,j,temp;
    for (i = 0; i < n; i++)
    {
        for(j = 0; j < n-1 ; j++)
        {
            if(compare(a[j],a[j+1]) > 0)
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main()
{
    int i, a[] = {-31,22,-1,50,-6,4};
    bubblesort(a,6,compare);
    for (int i = 0; i < 6; i++)
        printf("%d ",a[i]);
}