#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

int front=0,rear=-1;
int *arr=NULL;

int main()
{
    arr=(int *)malloc(sizeof(int)*SIZE);

    while(1)
    {
        printf("Press 1 to enqueue.\nPress 2 to dequeue.\nPress 3 to view front.\nPress 4 to show all elements of queue.\nPress any other key to exit.\n");
        int choice;
        scanf("%d",&choice);

        if(choice==1)
        {
            //insert
            int data;
            scanf("%d",&data);

            if(rear+1<SIZE)
            {
                arr[++rear]=data;
            }
            else
            {
                printf("QUEUE ALREADY FULL\n");
            }
        }
        else if(choice==2)
        {
            if(front+1<=rear)
            {
                front++;

                if(front==rear)
                {
                    //resetting the pointers so that it is reusable
                    front=0;
                    rear=-1;
                }
            }
            else
            {
                printf("QUEUE EMPTY\n");
            }
        }
        else if(choice==3)
        {
            if(rear!=-1)
            {
                printf("FRONT ELEMENT : %d\n",arr[front]);
            }
            else
            {
                printf("QUEUE EMPTY\n");
            }
        }
        else if(choice==4)
        {
            while(front<=rear)
            {
                printf("%d , ",arr[front]);
                front++;
            }
            printf("\n");
        }
        else
        break;
    }
}