// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// TODO: Complete the function
float half(float bill, float tax, int tip)
{
    // printf("original_bill %f\n",bill);
    float bill_after_tax = bill + ((tax / 100) * bill);
    // printf("bill_after_tax addition %f\n",bill_after_tax);
    // printf("in float as input tax %f\n",tax / 100);
    // printf("typecasting of ")
    // printf("tip input %f\n",(float)tip / 100);
    float tip_after_tax = ((float) tip / 100) * bill_after_tax;
    // printf("bill %f\n",tax);
    // printf("tip_after_tax addition %f\n",tip_after_tax);
    float total = (tip_after_tax + bill_after_tax) / 2;

    return total;
}
