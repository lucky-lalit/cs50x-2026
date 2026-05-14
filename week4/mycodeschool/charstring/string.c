#include <stdio.h>

int main()
{
    char c[10];
    c[0] = 'J';
    c[1] = 'O';
    c[2] = 'H';
    c[3] = 'N';
    // c[4] = '\0';
    for(int i = 0; i < 10; i++)
    {
        printf("the value at %d is %d\n", i, c[i]);
    }
    // printf("%s\n",c);
}