#include <cs50.h>
#include <stdio.h>

int factorial(int num);

int main(void)
{
    int input = get_int("Enter a number for a factorial: ");
    printf("%i\n", factorial(input));
}

int factorial(int num)
{
    // Base case
    if (num == 0)
    {
        return 1;
    }
    // Recusive case
    return num * factorial(num - 1);



}
