#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

//in this program we sorting the push in the list so their are four possibilities one first push , second in starting,
//thrid is at end(loop) , and fourth is at last(loop)


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

    node *ptr = list;
    while(ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
    return 0;

}
