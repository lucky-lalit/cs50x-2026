#include <cs50.h>
#include <stdio.h>

int fib(int num);

int main(void)
{
    int input = get_int("Enter a number for a fibonacci: ");
    printf("%i\n", fib(input));
}

int fib(int num)
{
    printf("debug_1 %i\n",num);
    // Base case
    if (num == 0)
    {
        return 0;
    }
    if (num == 1)
    {
        return 1;
    }
    // Recusive case
    int minus_1 = fib(num - 1);
    int minus_2 = fib(num - 2);
    return minus_1 + minus_2;
    // return fib(num - 2) + fib(num - 1);



}
