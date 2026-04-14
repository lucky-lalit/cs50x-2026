#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string input = get_string("Text: ");
    int index =
        round((0.0588 * ((count_letters(input) / (float) count_words(input)) * 100)) -
              (0.289 * ((count_sentences(input) / (float) count_words(input)) * 100)) - 15.8);
    if (round(index) < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (round(index) > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    int letter = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // if (65 <= toupper(text[i])  && toupper(text[i]) <= 90)
        if (isalpha(text[i]))
        {
            letter++;
        }
    }
    return letter;
}

int count_words(string text)
{
    int words = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == 32)
        {
            words++;
        }
    }
    return words + 1;
}

int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }
    return sentences;
}
