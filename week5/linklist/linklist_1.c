#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

typedef struct node{
    int data;
    struct node* next;
}node;

int main()
{
    node *list = NULL;

    for (int i = 0; i < 3; i++)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
            return -1;
        n->data = get_int("Number: ");
        n->next = NULL;

        n->next = list;
        list = n;
    }
    return 0;
}

