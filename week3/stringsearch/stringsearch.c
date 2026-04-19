#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    string input = get_string("Enter the string which needs to search: ");

    for (int i = 0; i < 6; i++)
    {
        if(strcmp(strings[i],input) == 0)
        {
            printf("Found the string\n");
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}
