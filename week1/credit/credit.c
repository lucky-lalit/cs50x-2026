#include <cs50.h>
#include <stdio.h>

int get_first_two_digits(long card_number);
int get_first_digit(long card_number);

int main(void)
{
    int count = 0;
    long card_number = get_long("Number: ");
    long temp_copy = card_number;
    while (temp_copy != 0)
    {
        temp_copy = temp_copy / 10;
        count++;
    }
    if (count < 13)
    {
        printf("INVALID\n");
        return 0;
    }

    int sum = 0;
    temp_copy = card_number;
    for (int i = 0; i <= count; i++)
    {

        if (i % 2 == 0)
        {
            sum += temp_copy % 10;
        }
        else
        {
            int temp = temp_copy % 10;

            sum += temp * 2 / 10;
            sum += temp * 2 % 10;
        }
        temp_copy = temp_copy / 10;
    }
    int digits = get_first_two_digits(card_number);
    int digit = get_first_digit(card_number);

    if (sum % 10 == 0)
    {
        if ((digits == 34 || digits == 37) && (count == 15))
        {
            printf("AMEX\n");
        }
        else if ((digits >= 51 && digits <= 55) && count == 16)
        {
            printf("MASTERCARD\n");
        }
        else if (digit == 4 && (count == 13 || count == 16))
        {
            printf("VISA\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
int get_first_two_digits(long card_number)
{
    while (card_number > 100)
    {
        card_number = card_number / 10;
    }
    return card_number;
}
int get_first_digit(long card_number)
{
    while (card_number > 10)
    {
        card_number = card_number / 10;
    }
    return card_number;
}
