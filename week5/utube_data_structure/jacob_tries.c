#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct trienode{
    struct trienode *children[256];
    bool terminal;
}trienode;

trienode *createnode()
{
    trienode *node = malloc(sizeof(trienode));
    if (node == NULL)
        return NULL;
    for (int i = 0; i < 256; i++)
        node->children[i] = NULL;
    node->terminal = false;
    return node;
}

bool trieinsert(trienode **root, char *signedtext)
{
    if (*root == NULL)
        *root = createnode();

    unsigned char *text= (unsigned char *)signedtext;
    trienode *temp = *root;
    int len = strlen(signedtext);


    for (int i = 0; i < len; i++)
    {
        if (temp->children[text[i]] == NULL)
        {
            //create new node
            temp->children[text[i]] = createnode();
        }
        temp = temp->children[text[i]];

    }
    if (temp->terminal)
    {
        return false;
    }else{
        temp->terminal = true;
        return true;
    }

    }

void printtrie_rec(trienode *node, unsigned char *prefix, int length) {
    unsigned char newprefix[length+2];
    memcpy(newprefix, prefix, length);
    newprefix[length+1] = 0;

    if (node->terminal) {
        printf("WORD: %s\n", prefix);
    }

    for (int i=0; i < 256; i++) {
        if (node->children[i] != NULL) {
            newprefix[length] = i;
            printtrie_rec(node->children[i], newprefix, length+1);
        }
    }
}

void printtrie(trienode *root)
{   
    if (root == NULL)
    {
        printf("TRIE EMPTY\n");
        return;
    }
    printtrie_rec(root, NULL, 0);
}
int main()
{

    trienode *root = NULL;

    trieinsert(&root, "KIT");
    trieinsert(&root, "CATTLE");
    trieinsert(&root, "KIN");
    trieinsert(&root, "CAT");
    trieinsert(&root, "HAPPY");
    printtrie(root);


}
