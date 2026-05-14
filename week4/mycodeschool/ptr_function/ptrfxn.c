#include <stdio.h>

void printHello(char *name )
{
    printf("Hello World %s\n",name);
}
// int add(int a,int b)
// {
//     return a+b;
// }

int main()
{
    // int c;
    // void (*p)(int,int);
    // p = add;
    // c = (p)(2,3);
    // printf("%d\n",c);

    void (*ptr)();
    ptr = printHello;
    ptr("Tom");
}