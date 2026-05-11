#include <stdio.h>

#define N 5

int main()
{
    int a[N], *p;
    printf("Enter 5 elements in the array:  %d\n", N);
    for (p = a; p <= (a + N) - 1; p++)
        scanf("%d", p);

    printf("Elements in the reverse order:- \n");
    for (p = (a + N) - 1; p >= a; p--)
        printf("%d\n", *p);
    return 0;
}
