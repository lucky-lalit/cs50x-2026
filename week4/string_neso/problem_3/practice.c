#include <stdio.h>
#include <string.h>

int main()
{
    char c[] = "GATE2011";
    char *p = c;
    // printf("%s\n",p);
    printf("%s\n",p+p[3]-p[1]);
    printf("%d\n",p[2]);
}