#include <stdio.h>
#include <string.h>
//is it necessary to store the return type of strcpy in any variable??
//because my code gives error in output it gives unexpected output..  i think i got it we have to manually indicate the end of the string
// Hell0
//HeHell0 
int main()
{
    char str1[10] = "Helloasf";
    char str2[2];
    char str3[4];

    printf("%p\n",str1);
    printf("%s, %u, %d\n",str1,&str1[0],sizeof(str1));
    printf("%s, %u, %d\n",str2,str2,sizeof(str2));
    printf("%s, %u, %d\n",str3,&str3[0],sizeof(str3));
    // printf("%s\n",str1);
    strcpy(str2,str1);
    printf("%s, %u, %d\n",str1,str1,sizeof(str1));
    printf("%s, %u, %d\n",str2,str2,sizeof(str2));
    // printf("%s\n",str2);
    // printf("%d\n",sizeof(str3));
    // printf("%s\n",str1);
    // printf("%s\n",str3);
    strncpy(str3,str1,sizeof(str3));
    str3[sizeof(str3) - 1] = '\0';
    printf("%s\n",str1);
    printf("%s\n",str2);
    printf("%s\n",str3);
    char str4[5];
    char str5[5];
    printf("%u, %u\n",str4,str5);
    return 0;
    // char str[5];
}



// main aaattaaa