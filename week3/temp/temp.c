// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>

#define NUM_CITIES 10

typedef struct
{
    string city;
    int temp;
} avg_temp;

avg_temp temps[NUM_CITIES];

void sort_cities(void);

int main(void)
{
    temps[0].city = "Austin";
    temps[0].temp = 97;
    // temps[0].temp = 90;

    temps[1].city = "Boston";
    temps[1].temp = 82;
    // temps[1].temp = 99;

    temps[2].city = "Chicago";
    temps[2].temp = 85;
    // temps[2].temp = 98;

    temps[3].city = "Denver";
    temps[3].temp = 90;
    // temps[3].temp = 97;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;
    // temps[4].temp = 96;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;
    // temps[5].temp = 95;

    temps[6].city = "Miami";
    temps[6].temp = 97;
    // temps[6].temp = 94;

    temps[7].city = "New York";
    temps[7].temp = 85;
    // temps[7].temp = 93;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;
    // temps[8].temp = 92;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;
    // temps[9].temp = 91;

    sort_cities();

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

// TODO: Sort cities by temperature in descending order
void sort_cities(void)
{
    // bool swap = false;
    // Add your code here
    for (int i = 0; i < NUM_CITIES; i++)
    {
        // if (temps[i].temp < temps[j + 1].temp)

        // if (i > 0 && !swap)
        //     break;
        bool has_swapped = false;

        for (int j = 0; j < NUM_CITIES - (i + 1); j++)
        {
            if (temps[j].temp < temps[j + 1].temp)
            {
                avg_temp swap_struct = temps[j];
                temps[j] = temps[j + 1];
                temps[j + 1] = swap_struct;
                has_swapped = true;
                //     int swap_temp = temps[j].temp;
                //     string swap_city = temps[j].city;
                //     temps[j].temp = temps[j + 1].temp;
                //     temps[j].city = temps[j + 1].city;
                //     temps[j + 1].temp = swap_temp;
                //     temps[j + 1].city = swap_city;
            }
        }
        if (!has_swapped)
            break;
    }
    // for (int i = 0; i < 10; )
}
