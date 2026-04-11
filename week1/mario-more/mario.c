#include <cs50.h>
#include <stdio.h>
void print_row_left(int bricks);
void print_row(int spaces, int bricks);
int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++)
    {
        print_row(height - i, i + 1);
        print_row_left(i + 1);
    }
}
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
    printf("  ");
}
void print_row_left(int bricks)
{
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    printf("\n");
}
