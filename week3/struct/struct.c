#include <cs50.h>
#include <stdio.h>

typedef struct
{
    string name;
    int votes;
} candidate;

int main(void)
{
    candidate A;
    // candidate A = {.name = "Alice", .votes = 8};
    A.name = "Alice";
    A.votes = 8;
    printf("%s has %i of votes\n", A.name, A.votes );
}
