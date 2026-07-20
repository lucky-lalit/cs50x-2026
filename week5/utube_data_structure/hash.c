#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (person *)(0xFFFFFFFFFFFFFFUL)

typedef struct {
    char name[MAX_NAME];
    int age;
}person;
person *hash_table[TABLE_SIZE];


// it is the funtion that will return integer ranging between 0 to 9
unsigned int hash(char *name)
{
    int length = strlen(name);
    if (length > MAX_NAME)
        length = MAX_NAME;
    unsigned int hash_value = 0;


    for (int i =0; i < length; i++)
    {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}
//setting the table all the values to NULL
void init_hash_table(){
    for (int i = 0; i < TABLE_SIZE; i++)
        hash_table[i] = NULL;
}

void print_table(){
    printf("start\n");
    for (int i =0; i < TABLE_SIZE; i++)
    {
        if (hash_table[i] == NULL)
            printf("\t%i\t---\n",i);
        else if (hash_table[i] == DELETED_NODE)
            printf("\t%i\t----<deleted>\n",i);
        else
            printf("\t%i\t%s\n",i,hash_table[i]->name);
    }
    printf("\tEnd\n");
}

bool hash_table_insert(person *p)
{
    if (p == NULL) return false;
    int index = hash(p->name);
    for (int i = 0; i < TABLE_SIZE ; i++)
    {
        int try = (index + i) % TABLE_SIZE;
        if (hash_table[try] == NULL || hash_table[try] ==  DELETED_NODE)
        {
            hash_table[try] = p;
            return true;
        }
    }
    return false;

}

//finds the person in the table by its name
person *hash_table_lookup(char *name)
{
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (index + i) % TABLE_SIZE;
        if (hash_table[try] == NULL)
            return false;
        if (hash_table[try] == DELETED_NODE) continue;
        if ((strcmp(hash_table[try]->name,name) == 0))

            return hash_table[try];
    }
    return NULL;
}

person *hash_table_delete(char *name)
{
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (index + i) % TABLE_SIZE;
        if (hash_table[try] == NULL) return NULL;
        if (hash_table[try] == DELETED_NODE) continue;
    if ((strcmp(hash_table[try]->name,name) == 0))
    {
        person *temp = hash_table[try];
        hash_table[try] = DELETED_NODE;
        return temp;
        }
    }
        return NULL;
}



int main()
{
    init_hash_table();
    print_table();

    person jacob = {.name = "Jcob", . age = 256};
    person kate = {.name = "kate", . age = 27};
    person mpho = {.name = "Mpho", . age = 14};
    person sarah = {.name = "Sarah", . age = 54};
    person edna = {.name = "Edna", . age = 15};
    person maren = {.name = "Maren", . age = 25};
    person eliza = {.name = "Eliza", . age = 34};
    person robert = {.name = "robert", . age = 1};
    person jane = {.name = "Jane", . age = 75};


    hash_table_insert(&jacob);
    hash_table_insert(&kate);
    hash_table_insert(&mpho);
    hash_table_insert(&sarah);
    hash_table_insert(&edna);
    hash_table_insert(&maren);
    hash_table_insert(&eliza);
    hash_table_insert(&robert);
    hash_table_insert(&jane);

    print_table();

    person *temp = hash_table_lookup("Mpho");
    if (temp == NULL)
        printf("NOT FOUND\n");
    else
        printf("FOUND %s\n",temp->name);

    temp = hash_table_lookup("Lalit");
    if (temp == NULL)
        printf("NOT FOUND\n");
    else
        printf("FOUND %s\n",temp->name);

    hash_table_delete("Mpho");
    temp = hash_table_lookup("Mpho");
    if (temp == NULL)
        printf("NOT FOUND\n");
    else
        printf("FOUND %s\n",temp->name);


print_table();

    // printf("LALIT=> %u\n",hash("LALIT"));
    // printf("Rahul=> %u\n",hash("Rahul"));
    // printf("Shiv=> %u\n",hash("Shiv"));
    // printf("Harsh=> %u\n",hash("Harsh"));
}
