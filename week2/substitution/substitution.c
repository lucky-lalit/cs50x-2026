#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char replace_character(char input_char, string key);

int main(int argc, string argv[])
{
    // printf("%i\n",argc);
    if (argc != 2)
    {
        printf("enter a valid number of keys\n");
        return 1;
    }
    int len = strlen(argv[1]);
    if (len != 26)
    {
        printf("key must contaion 26 characters\n");
        return 1;
    }

    for (int i = 0; i < len; i++)
    {
        // printf("debug1");
        if (isalpha(argv[1][i]))
        {
            // int count = 1;
            for (int j = i + 1; j < len; j++)
            // printf("debug2");
            {
                if (tolower(argv[1][i]) == tolower(argv[1][j]))
                {
                    // printf("%i %i\n", i, j);
                    printf("character in the key cannot be repeated\n");
                    return 1;
                }
                // continue;
            }
        }
        else
        {
            printf("key should contain only alphabets\n");
            return 1;
        }
    }

    string input = get_string("plaintext:  ");
    printf("ciphertext: ");

    for (int i = 0, input_len = strlen(input); i < input_len; i++)
    // printf("debug3");
    {
        printf("%c", replace_character(input[i], argv[1]));
    }
    printf("\n");
}

char replace_character(char input_char, string key)
{

    if (islower(input_char))
    {
        return tolower(key[input_char - 'a']);
    }
    else if (isupper(input_char))
    {
        return toupper(key[input_char - 'A']);
    }

    return input_char;
}
