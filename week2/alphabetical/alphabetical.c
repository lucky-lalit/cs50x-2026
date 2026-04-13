#include<cs50.h>
#include<stdio.h>
#include<string.h>

int main(void)
{
    string text = get_string("Text: ");
    for(int i=0, len = strlen(text); i < len-1; i++)
        {
            printf("%c %i\n", text[i], text[i]);
        if(text[i] > text[i+1])
        {
            printf("NO\n");
            return 0;
        }
    }   printf("Yes\n");

}
