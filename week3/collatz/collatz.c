#include <cs50.h>
#include <stdio.h>

int collatz(int n);

int steps = 0;

int main(void)
{
    int input = get_int("Enter a number: ");
    printf("%i\n", collatz(input));
}

// int collatz(int n)
// {
//     if(n == 1)
//         return 0;
//     else if(n % 2 == 0)
//         return 1 + collatz(n/2);
//     else
//         return 1 + collatz((3 * n) + 1);
// }

int collatz(int n)
{
    // int steps;
    // printf("debug1 %i\n", n);
    if (n == 1)
        // {   printf("debug2 %i\n" , steps);
        return steps;
    // }
    // printf("debug3 %i\n" , steps);
    steps++;
    // printf("debug4 %i\n" , steps);
    if (n % 2 == 0)
        // {
        // steps++;
        return collatz(n / 2);
    // }
    else
        // {
        // steps++;
        return collatz((3 * n)+1);
    // }
    // return steps;
}
