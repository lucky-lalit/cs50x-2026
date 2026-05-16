#include <stdio.h>
#include <string.h>

int main()
{
    char p[20];
    char *s = "string";
    int len = strlen(s);
    int i;
    for (i = 0; i < len; i++)
    {
        p[i] = s[len - i];
    }
    printf("%s\n",p);
}