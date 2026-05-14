#include <stdio.h>
#include <stdlib.h>

// int c;
void printHelloWorld()
{
    printf("Hello World\n");
}

int *add(int *x, int *y)
{
    int *c = (int *)malloc(sizeof(int));
    *c = (*x) + (*y);
    return c; 
}

int main()
{
    int a = 2, b = 4;
    int *ptr = add(&a,&b);
    // printf("Sum: %d\n",*ptr);
    printHelloWorld();
    printf("Sum: %d\n",*ptr);
}