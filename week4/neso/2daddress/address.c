#include <stdio.h>

int main()
{
    int a[100][100];
    // printf("%p\n",a);
    // printf("%p\n",&(a[40][50]));

    int *base = &a[0][0];
    printf("%p\n",base);
    int *cal = base + (40 * 100 + 50);
    printf("%p\n",cal);

    printf("%td\n",(cal - base));
}