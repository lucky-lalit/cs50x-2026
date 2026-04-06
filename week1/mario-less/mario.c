#include <cs50.h>
#include <stdio.h>

void print_row(int spaces, int bricks);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height ");
    }
    while (height < 1);

    for (int i = 0; i < height; i++)
        print_row(height - i, i + 1);
}
// }

void print_row(int spaces, int bricks)
{
    for (int i = 0; i < spaces - 1; i++)
    {
        printf(" ");
    }
    for (int j = 0; j < bricks; j++)
    {
        printf("#");
    }
    printf("\n");
}
