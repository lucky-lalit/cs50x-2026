#include <stdio.h>
#include <stdlib.h>

int cash = 100;

int main()
{
    int bet;
    while(cash > 0)
    {
        printf("What's the bet ? \n");
        scanf("%d",&bet);
        if(bet == 0 || bet > cash)
    }
}