#include <stdio.h>
#include <string.h>

int main()
{
    char str1[10],str2[100];
    strcpy(str1,"Hello My");
    strcpy(str2,"Self is Lalit Tiwari currently pursuing BE in IT");
    strcat(str1,str2);
    //safe version to handle
    // strncat(str1,str2,sizeof(str1) - strlen(str1) -1); 
    printf("%s\n",str1);

}