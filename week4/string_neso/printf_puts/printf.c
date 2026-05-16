#include <stdio.h>

int main()
{
    char *s = "Hello World";
    printf("%.5s\n",s);

    // printf("****************************************************************\n");

    // crating shells
    //dosen't gives error when we write the array size less then string slice
    printf("%6.5s\n",s);


    // printf("****************************************************************\n");

    puts(s);
    puts(s);
}