#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p;
    char *p0;
    void *ptr = (int*)calloc(2,sizeof(int));
    p = (int *)ptr;
    p0 = (char*)ptr;
    printf("all the elements of p array\n");
    for (int i = 0; i < 2; i++)
    {
        printf("the value %d at %d : %d\n",*(p+i),(p+i)),i;
        
    }
    printf("all the elements of p0 array\n");
    for (int i = 0; i < 8; i++)
    {
        printf("the value %d %c at %d : %d \n",*(p0+i),*(p0+i),(p0+i),i);
    }
    

    p[0] = 1145258561;
    // printf("debug %d\n",());
    p[1] = p[0] + 20;


    printf("all the elements of p array\n");
    for (int i = 0; i < 2; i++)
    {
        printf("the value %d at %d : %d \n",*(p+i),(p+i),i);
        
    }
    printf("all the elements of p0 array\n");
    for (int i = 0; i < 8; i++)
    {
        printf("the value %d %c at %d : %d \n",*(p0+i),*(p0+i),(p0+i),i);
    }

}