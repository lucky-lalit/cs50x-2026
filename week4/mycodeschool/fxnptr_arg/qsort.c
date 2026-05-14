#include <stdio.h>
#include <stdlib.h>

int comapre(const void *a,const void *b)
{
    int A = *((int*)a);
    int B = *((int*)a);
    return A- B;
}

int main()
{
    int i, a[] = {-31,22,-1,50,-6,4};
    qsort(a,6,sizeof(int))
}