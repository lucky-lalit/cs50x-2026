#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    string name = get_string("Input: ");
    for(int i = 0, len = strlen(name); i < len; i++)
    {
        printf("%c", name[i]);
    }
    printf("\n");
}
