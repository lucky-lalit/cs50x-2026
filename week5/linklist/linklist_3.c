    #include <stdio.h>
    #include <stdlib.h>
    #include <cs50.h>

    //in this program we appending the new after one and the first node address is stored in the list
    //then for next node we reach till the end node y checking the ptr->next == NULL, when we reach to that node we push new.

    typedef struct node
    {
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
                return -1;
            n->data = get_int("NUmber: ");
            n->next = NULL;

            if (list == NULL)
            {
                list = n;
            }
            else{
                for (node *ptr = list; ptr != NULL; ptr = ptr->next)
                {
                    if(ptr->next == NULL)
                    {
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
