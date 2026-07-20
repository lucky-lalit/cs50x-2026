#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
int hash(string word)
{
    if (word == NULL || strlen(word) < 2)
        return -1;
    if (isalpha(word[0]) && isalpha(word[1]))
        return (((toupper(word[0]))- 'A' * 100) + toupper(word[1])) - 'A';
    else
        return -2;
}

int main()
{
    string word = get_string("Enter the string: ");
    printf("%i\n",hash(word));
}
