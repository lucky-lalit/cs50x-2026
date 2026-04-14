#include <cs50.h>
#include <stdio.h>

bool valid_triangle(float a,float b,float c);

int main(void)
{
float x = get_float("Enter first side of triangle: ");
float y = get_float("Enter first side of triangle: ");
float z = get_float("Enter first side of triangle: ");

bool result = valid_triangle(x, y, z);
printf("%b\n", result);

}


bool valid_triangle(float a,float b,float c)
{
    // printf("debug0 %f %f %f", a, b, c);
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return false;
    }
    if (a + b <= c || a + c <= b || b + c <= a)
    {
        return false;
    }
    return true;
}
