#include <stdio.h>

int input(char str[],int n)
{
    int ch,i = 0;
    // is it a feature of getchar that it  itself increments the count
    while((ch = getchar()) != '\n')
    {
        if (i < n)
        {
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i; 

    // }
}

int main()
{
    char str[100];
    // printf("Enter the string: ");
    // gets(str);
    int n  = input(str,5);
    printf("%d %s", n, str);
    return 0;
}