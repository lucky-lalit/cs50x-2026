#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
// #define DELETED_NODE (person *)(0xFFFFFFFFFFFFFFUL)

typedef struct person{
    char name[MAX_NAME];
    int age;
    struct person *next;
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
        else{
            printf("\t%i\t",i);
            person *temp =hash_table[i];
            while(temp != NULL)
            {
                printf("%s--",temp->name);
                temp = temp->next;
            }
            printf("\n");
        }

    }
    printf("\tEnd\n");
}

bool hash_table_insert(person *p)
{
    if (p == NULL) return false;
    int index = hash(p->name);
    p->next = hash_table[index];
    hash_table[index] = p;
    return true;
    }


//finds the person in the table by its name
person *hash_table_lookup(char *name)
{
    int index = hash(name);
    person *temp = hash_table[index];
    while(temp != NULL && strncmp(temp->name,name,256) != 0)
    {
        temp= temp->next;
    }
    return temp;
}

person *hash_table_delete(char *name)
{
    int index = hash(name);
    person *temp = hash_table[index];
    person *prev = NULL;
    while(temp != NULL && strncmp(temp->name,name,256) != 0)
    {
        prev = temp;
        temp= temp->next;
    }
    if (temp == NULL) return NULL;
    if (prev == NULL)
    {
        hash_table[index] = temp->next;
    }
    else {
        prev->next = temp->next;
    }

    return temp;
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




















// #include <stdio.h>
// #include <stdlib.h>
// #include <stdint.h>
// #include <stdbool.h>
// #include <string.h>

// #define MAX_NAME 256
// #define TABLE_SIZE 10
// // #define DELETED_NODE (person *)(0xFFFFFFFFFFFFFFUL)

// typedef struct person{
//     char name[MAX_NAME];
//     int age;
//     struct person *next;
// }person;
// person *hash_table[TABLE_SIZE];


// //     hash_table_insert(&mpho);
//     hash_table_insert(&sarah);
//     hash_table_insert(&edna);
//     hash_table_insert(&maren);
//     hash_table_insert(&eliza);
//     hash_table_insert(&robert);
//     hash_table_insert(&jane);

//     print_table();

//     person *temp = hash_table_lookup("Mpho");
//     if (temp == NULL)
//         printf("NOT FOUND\n");
//     else
//         printf("FOUND %s\n",temp->name);

//     temp = hash_table_lookup("Lalit");
//     if (temp == NULL)
//         printf("NOT FOUND\n");
//     else
//         printf("FOUND %s\n",temp->name);

//     hash_table_delete("Mpho");
//     temp = hash_table_lookup("Mpho");
//     if (temp == NULL)
//         printf("NOT FOUND\n");
//     else
//         printf("FOUND %s\n",temp->name);


// print_table();

//     // printf("LALIT=> %u\n",hash("LALIT"));
//     // printf("Rahul=> %u\n",hash("Rahul"));
//     // printf("Shiv=> %u\n",hash("Shiv"));
//     // printf("Harsh=> %u\n",hash("Harsh"));
// }
