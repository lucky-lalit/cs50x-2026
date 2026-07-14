#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

typedef struct node{
    int data;
    struct node *next;
}node;
void unload(node *list);


int main()
{
    node *list = NULL;

    for (int i = 0; i < 3; i++)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }

        n->data = get_int("Number: ");
        n->next = NULL;

        if (list == NULL)
        {
            list = n;
        }

        else if (n->data < list->data)
        {
            n->next = list;
            list = n;
        }

        else {
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                if (ptr->next == NULL)
                {
                    ptr->next = n;
                    break;
                }

                if (n->data < ptr->next->data)
                {
                    n->next=ptr->next;
                    ptr->next = n;
                    break;

                }
            }



        }
    }


    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n",ptr->data);
    }
    unload(list);
    return 0;

}

void unload(node *list)
{
 node *ptr = list;
    while(ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}
