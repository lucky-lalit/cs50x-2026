#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
typedef struct node{
    int data;
    struct node *next;
}node;

void print(node *root)
{
    if (root == NULL) return;
    print(root->next);
    printf("%i\n",root->data);
}

int main()
{
    node *head = NULL;
    for (int i = 0; i < 3; i++)
    {
        node *ptr = malloc(sizeof(node));
        ptr->data = i + 1;
        ptr->next = NULL;

        ptr->next = head;
        head = ptr;
    }
    print(head);

    node *temp = head;
    while(temp!= NULL)
    {
        printf("%i\n",temp->data);
        temp = temp->next;
    }


}
