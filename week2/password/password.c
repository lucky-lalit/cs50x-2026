// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and "
               "symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool lowercase = false;
    bool uppercase = false;
    bool digit = false;
    bool symbol = false;
    // for(int i = 0; password[i] != '\0'; i++)
    int index = 0;
    while (password[index] != '\0')
    {
        if (!(lowercase) && islower(password[index]))
            lowercase = true;
        if (!(uppercase) && isupper(password[index]))
            uppercase = true;
        if (!(digit) && isdigit(password[index]))
            digit = true;
        if (!(symbol) && ispunct(password[index]))
            symbol = true;
        if (lowercase && uppercase && digit && symbol)
            return true;
        index++;
    }
    return false;
}
