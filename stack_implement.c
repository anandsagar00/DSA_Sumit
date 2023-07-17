#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

int *arr=NULL;
int top=-1;

int main()
{
    arr=(int *)malloc(sizeof(int)*SIZE);

    while(1)
    {
        //infinite loop to perform operation
        printf("Press 1 to push.\nPress 2 to pop.\nPress 3 to view top.\nPress 4 to show all elements of stack.\nPress any other key to exit.\n");
        int choice;
        scanf("%d",&choice);

        if(choice==1)
        {
            system("clear");
            int data;
            printf("ENTER DATA : ");
            scanf("%d",&data);
            if(top+1<SIZE)
            {
                arr[++top]=data;
            }
            else
            printf("STACK FULL.\n");
        }
        else if(choice==2)
        {
            system("clear");
            if(top>=0)
            {
                top--;
            }
            else
            printf("STACK ALREADY EMPTY.\n");
        }
        else if(choice==3)
        {
            system("clear");
            if(top!=-1)
            printf("TOP ELEMENT : %d\n",arr[top]);
            else
            printf("STACK IS EMPTY.\n");
        }
        else if(choice==4)
        {
            system("clear");
            while(top>=0)
            {
                printf("%d , ",arr[top--]);
            }
            printf("\n");
        }
        else
        break;
    }
}