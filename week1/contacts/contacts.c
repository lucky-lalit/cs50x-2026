#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("Name: ");
    int age = get_int("Age: ");
    string pnumber = get_string("Phone Number: ");
    string gender = get_string("Gender: ");
    string location = get_string("Location: ");

    printf("New contact: %s, %i is a %s, and lives in %s, can be contacted by %s\n", name, age,
           gender, location, pnumber);
}
