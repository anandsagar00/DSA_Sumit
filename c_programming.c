#include<stdio.h>
#include<stdlib.h>

int comparator(void* a,void* b)
{
    return (*(int*)a>*(int*)b);
}

int main()
{
    int arr[]={-324,235,3436,12,-35,34};

    qsort(arr,6,sizeof(int),comparator);

    for(int i=0;i<6;i++)
    printf("%d ",arr[i]);
}