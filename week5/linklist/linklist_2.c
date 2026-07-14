#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node *next;
}node;
void print_reverse(node *ptr);
void print_reverse(node *ptr)
{
    if (ptr == NULL)
        return;
    print_reverse(ptr->next);
    printf("%i\n",ptr->data);
}

int main()
{
    node *list = NULL;
    for (int i = 0; i < 3; i++)
    {
        node *n = malloc(sizeof(node));
        n->data = get_int("Number: ");
        n->next = NULL;

        n->next = list;
        list = n;
    }

    node *ptr = list;
    while(ptr != NULL)
    {
        printf("%i\n",ptr->data);
        ptr = ptr->next;
    }
    print_reverse(list);
    return 0;
}

