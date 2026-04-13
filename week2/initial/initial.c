#include<cs50.h>
#include<stdio.h>

int main(int argc,string argv[])
{   if(argc < 2)
    {
        printf("Please Enter First name and last name");
    }
    for (int i = 1; i < argc; i++)
    {
        printf("%c", argv[i][0]);
    }
    printf("\n");
}
