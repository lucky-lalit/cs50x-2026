// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <math.h>

#include "dictionary.h"
int count = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26*26*26*26*26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);
    node *temp = table[index];
    // if (temp == NULL)
    //     return false;
    while (temp != NULL)
    {
        if (strcasecmp(temp->word, word) == 0)
            return true;
        temp = temp->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int len = strlen(word);
    // if (len == 1)
    //     return (unsigned int) (tolower(word[0]) % N);
    // else if (len == 2)
    //     return (unsigned int) ((tolower(word[0]) + tolower(word[1])) % N);
    // else
    //     // int len = strlen(word);
    //     // int value = 0;
    //     // for (int i = 0; i < len; i++)
    //     // {
    //     // value += tolower(word[i]);
    //     // }
    //     // return (value * ((word[0]))) % N;
    //     return (unsigned int) ((tolower(word[0]) + tolower(word[1]) + tolower(word[2])) % N);
    // return toupper(word[0]) - 'A';

    // int len = strlen(word);
    // int base26_0 = 0;
    // int base26_1 = 0;
    // int base26_2 = 0;
    // if (len >= 1)
    //     base26_0 = tolower(word[0]) - 'a';
    // if (len >= 2)
    //     base26_1 = tolower(word[1]) - 'a';
    // if (len >= 3)
    //     base26_2 = tolower(word[2]) - 'a';
    // unsigned int final_hash = ((base26_0 * 1) + (base26_1 * 26) + (base26_2 * 676)) % N;
    // return final_hash;

    unsigned int final_hash = 0;
    for (int i = 0; i < 5; i++)
    {
        if (len >= (i + 1))
            final_hash += (tolower(word[i]) - 'a') * (unsigned int)pow(26,i);

    }
    return final_hash % N;

}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
        return false;
    char temp[LENGTH];
    while (fscanf(file, "%s", temp) != EOF)
    {
        node *space = malloc(sizeof(node));
        if (space == NULL)
            return false;
        strcpy(space->word, temp);
        int index = hash(space->word);
        space->next = table[index];
        table[index] = space;
        count++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO

    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *temp = table[i];
        // if (temp == NULL)
        //     return false;
        while (temp != NULL)
        {
            node *next = temp->next;
            free(temp);
            temp = next;
        }
        // return true;
    }
    return true;
    // return false;
}
