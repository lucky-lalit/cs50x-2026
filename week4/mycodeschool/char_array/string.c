#include <stdio.h>

void print(const char *c)
{
    while(*c != '\0')
    {
        printf("%c",*c);
        c++;
    }
}

int main()
{
    // char *c = "Hello";
    char c[20] = "Hello";
    // c[0] = 'M';
    print(c); 
}