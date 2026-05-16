#include <stdio.h>
// in gets() fxn their is no impact of char a[10] limit ? why it is not prefered ?

int main()
{
    char a[10];
    // printf("Enter the string: ");
    // scanf("%9s",a);
    gets(a);
    printf("%s",a);
}