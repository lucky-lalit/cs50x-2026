#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct trienode{
    struct trienode *children[26];
    bool endofword;
}trienode;

trienode *createnewnode()
{
    trienode *node = malloc(sizeof(trienode));

    for (int i = 0; i < 26; i++)
        node->children[i] = NULL;
    node->endofword = false;
    return node;

}

trienode *root = NULL;

void insert(char *word)
{
    trienode *current = root;
    for (int i = 0; word[i] != 0; i++)
    {
        int index = word[i] - 'a';

        if (current->children[index] == NULL)
        {
            current->children[index] = createnewnode();
        }
        current = current->children[index];
    }
    current->endofword = true;
}

bool search(char *word)
{
    trienode *current = root;

    for (int i = 0; word[i] != 0; i++)
    {
        int index = word[i] - 'a';
        if (current->children[index] == NULL)
            return false;
        // current = current->children[index];
        // if (word[i+1] == '\0' && current->endofword == false)
        // return false;
        current = current->children[index];
    }
    return current->endofword;
}

int main()
{
    root = createnewnode();

    char *words[] = {
        "the",
        "a",
        "there",
        "their",
        "any"
    };

    int n = sizeof(words) / sizeof(words[0]);

    for (int i = 0; i < n; i++)
    {
        insert(words[i]);
    }

    printf("Words inserted successfully!\n");
    printf("%i\n",search("ta"));
    return 0;
}
