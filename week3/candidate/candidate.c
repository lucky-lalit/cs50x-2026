#include <cs50.h>
#include <stdio.h>



typedef struct
{
    string name;
    int votes;
} candidate;

candidate get_candidate(void);

int main(void)
{
    candidate new_candidate = get_candidate();
    printf("Candidate is named %s and has %i votes.\n", new_candidate.name, new_candidate.votes);
}
candidate get_candidate(void)
{


    candidate new_candidate;
    new_candidate.name = get_string("Name: ");
    new_candidate.votes = get_int("Votes: ");

    return new_candidate;
}
