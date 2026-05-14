#include <stdio.h>

int main()
{
    int a = 5025;
    int *p;
    p = &a;
    printf("the size of data type: %d\n",sizeof(int));
    printf("the p is: %d and the value is: %d\n",p , *p);


    char *p0;
    p0 = (char*)p;
    printf("the size of data type: %d\n",sizeof(char));
    printf("the p is: %d and the value is: %u, and its chr value is %c\n",p0 , *p0, *p0);
    printf("the p is: %d and the value is: %u, and its chr value is %c\n",p0+1 , *p0+1, *p0+1);

    printf("the p is: %p and the value is: %u, and its chr value is %c\n",
       (void*)p0, (unsigned char)*p0, (unsigned char)*p0);

    printf("the p is: %p and the value is: %u, and its chr value is %c\n",
       (void*)(p0 + 1), (unsigned char)*(p0) + 1, (unsigned char)*(p0) + 1);

}