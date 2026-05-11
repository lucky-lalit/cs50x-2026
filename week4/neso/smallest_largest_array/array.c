#include <stdio.h>

void minmax(int arr[], int len, int *min,int *max)
{
    *min = *max =arr[0];
    int  i;
    for (i = 1; i < len; i++)
    {
        if (arr[i] > *max)
            *max = arr[i];
        if (arr[i] < *min)
            *min = arr[i];
    }
}

int main()
{
    int a[] = {23,4,21,98,987,45,32,10,123,986,50,3,4,5};
    int min, max;
    printf("size of a %d and size of a[0] %d\n",sizeof(a),sizeof(a[0]));
    int len = sizeof(a) / sizeof(a[0]);
    minmax(a,len,&min,&max);
    printf("minimumm: %d and maximum: %d\n",min,max);
    return 0;

}