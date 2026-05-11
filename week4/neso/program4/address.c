#include <stdio.h>

int main()
{
    unsigned int x[4][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    unsigned int *base = &x[0][0];
    // printf("%td, %td, %td", ((unsigned int*)(x + 3) - base), (*(x + 3) - base), (*(x + 2)+3 - base));
    printf("%u %u %u\n",(x+3),*(x+3),*(x+2)+3);
    printf("%u\n",x);
}