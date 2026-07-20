#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
typedef struct node{
    int data;
    struct node *next;
}node;

int main()
{
    node *list = NULL;
    for (int i = 0; i < 3; i++)
    {
        node *n = malloc(sizeof(node));
        // if (n == NULL)
        // {
        //     printf("Malloc Failed\n");
        //     return -1;
        // }
        n->data = get_int("Enter number: ");
        n->next = list;

        list = n;
    }

    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n",ptr->data);
    }
    node *ptr = list;
    while(ptr != NULL)
    {
        node *temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
}
