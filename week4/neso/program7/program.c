#include <stdio.h>

int f(int x, int *py, int **ppz)
{
    int y, z;
    **ppz += 1;
    printf("z before %d\n",z);
    z = **ppz;
    printf("z after %d\n",z);
    printf("test %d\n", *py);
    *py +=2;
    printf("test %d\n", *py);
    y = *py;
    printf("y after %d\n",y);
    printf("x %d\n", x);
    x += 3;
    printf("x after %d\n", x);
    return x + y + z;
}


int main()
{
    int c, *b , **a;
    c = 4, b = &c, a =&b;
    printf("%d\n",f(c,b,a));
}