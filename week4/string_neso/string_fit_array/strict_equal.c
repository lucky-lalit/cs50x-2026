// VIDEO 5 

#include <stdio.h>

int main()
{
    //why don't it gives error when i don't write null character i.e s[5] = "Hello" why is it externally needed to add '\0' in t[i]
    //and actually it dosen't gives error then why neso did it and for s it automatically takes last character as '\0'
    char s[6] = "Hello";
    char t[6];

    int i;
    for(i = 0; s[i] != '\0' ; i++)
    {
        t[i] = s[i];
    }
    // t[i] = '\0';

    // printf("%s\n",s);
    printf("%s\n",t);
    return 0;
}