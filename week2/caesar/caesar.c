#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char rotate(char c, int k);
bool only_digits(string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Error: Enter valid key\n");
        return 1;
    }
    if (only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // return 0;

    string input = get_string("plaintext:  ");
    printf("ciphertext: ");

    for (int i = 0, len = strlen(input); i < len; i++)
    {
        printf("%c", rotate(input[i], atoi(argv[1])));
    }
    printf("\n");
    // printf("debug3 %c\n",rotate('H',13));
}
bool only_digits(string s)
{
    int count = 0;
    // int len = strlen(s);
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        // printf("debug1 %i\n", isdigit(s[i]));
        if (isdigit(s[i]) == 0)
        {
            return false;
        }
        // if (i == len-1)
        // {
        //     return true;
        // }
        // continue;
    }
    // printf("debug2 %i %i\n",count);
    // if (count > 0)
    // {
    // return false;
    // }
    return true;
}

char rotate(char c, int k)
{
    // printf("debug3 %c %i\n", c, k);
    // int digit = atoi(k);
    if (isalpha(c))
    {
        if (isupper(c))
        {
            // printf("debug4 %c\n", c);
            // printf("debug5 %c\n", (c + k - 65) % 26 + 65);
            return (c + k - 'A') % 26 + 'A';
        }
        else if (islower(c))
        {
            return ((c + k - 'a') % 26 + 'a');
        }
    }
    // printf("debug6 %c\n", c);
    return c;
}
