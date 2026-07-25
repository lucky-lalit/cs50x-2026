// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
char *replace(char *input);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("please enter a single cmd line argumnet\n");
        return 1;
    }

    char *result = replace(argv[1]);
    printf("%s\n", result);
}

char *replace(char *input)
{
    // int index = 0;
    // int len = strlen(input);
    // char *replaced_string = malloc(len + 1);
    // for (int i = 0; i < len; i++)
    // {
    //     if (input[i] == 'a')
    //         input[i] = '6';
    //     else if (input[i] == 'e')
    //         input[i] = '3';
    //     else if (input[i] == 'i')
    //         input[i] = '1';
    //     else if (input[i] == 'o')
    //         input[i] = '0';
    //     replaced_string[i] = input[i];
    // }
    // replaced_string[len] = '\0';
    // return replaced_string;
    // while(input[index] != '\0')
    // {
    //     if (index[])
    // }
    int index = 0;
    // while (input[index] != '\0')
    // {
    //     if (tolower(input[index]) == 'a')
    //         input[index] = '6';
    //     else if (tolower(input[index]) == 'e')
    //         input[index] = '3';
    //     else if (tolower(input[index]) == 'i')
    //         input[index] = '1';
    //     else if (tolower(input[index]) == 'o')
    //         input[index] = '0';
    //     index++;
    // }
    // return input;

    while (input[index] != '\0')
    {
        switch (tolower(input[index]))
        {
            case 'a':
                input[index] = '6';
                break;
            case 'e':
                input[index] = '3';
                break;
            case 'i':
                input[index] = '1';
                break;
            case 'o':
                input[index] = '0';
                break;
        }
        index++;
    }
    return input;
}
