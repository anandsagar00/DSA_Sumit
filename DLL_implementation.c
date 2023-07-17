#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data; 
    struct Node* prev;
    struct Node* next;
};

typedef struct Node Node;

Node* getNode(int data)
{
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->data=data;
    temp->prev=NULL;
    temp->next=NULL;
    return temp;
}

Node* append(Node* head,int data)
{
    if(head==NULL)
    {
        head=getNode(data);
    }
    else
    {
        Node *curr=head;

        while(curr->next!=NULL)
        {
            curr=curr->next;
        }

        Node* temp=getNode(data);

        curr->next=temp;
        temp->prev=curr;
    }
    return head;
}

Node* insertAt(Node* head,int data,int pos)
{
    if(pos==1)
    {
        Node* temp=getNode(data);
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    else
    {
        int i=1;

        Node* curr=head;

        while(curr!=NULL && i<pos)
        {
            if(i==pos-1)
            {
                Node* newNode=getNode(data);
                
                newNode->next=curr->next;
                newNode->prev=curr;

                if(curr->next!=NULL)//if the next node exists then
                {
                    curr->next->prev=newNode;
                }

                curr->next=newNode;
                break;

            }
            i++;
            curr=curr->next;
        }

    }
    return head;
}

Node* deleteAt(Node* head,int pos)
{
    if(pos==1)
    {
        Node* temp=head;
        head=head->next;
        head->prev=NULL;

        free(temp);
    }
    else
    {
        int i=1;
        Node* curr=head;
        while(curr!=NULL && i<=pos)
        {
            if(i==pos)
            {
                curr->prev->next=curr->next;
                if(curr->next)
                curr->next->prev=curr->prev;

                free(curr);
                break;
            }
            i++;
            curr=curr->next;
        }
    }
    return head;
}

void printList(Node* head)
{
    Node* tail=NULL;
    printf("\nNormal Order : ");
    while(head!=NULL)
    {
        printf("%d <=> ",head->data);
        tail=head;
        head=head->next;
    }
    printf("\nReverse Order : ");
    while(tail!=NULL)
    {
        printf("%d <=> ",tail->data);
        tail=tail->prev;
    }
    printf("\n");
}


int main()
{
    Node* head=NULL;
    while (1)
    {
        int choice;
        printf("Press 1 to append .\nPress 2 to insert at given position.\nPress 3 to delete at given position\nPress 4 to insert after a given position\nPress any other key to exit.\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            int data;
            system("clear");
            printList(head);
            printf("Enter Data to append : ");
            scanf("%d",&data);
            head=append(head,data);
            printList(head);
        }
        else if(choice==2)
        {
            int data,pos;
            system("clear");
            printList(head);
            printf("Enter Data to insert : ");
            scanf("%d",&data);
            printf("Enter position to insert : ");
            scanf("%d",&pos);
            head=insertAt(head,data,pos);
            printList(head);
        }
        else if(choice==3)
        {
            int pos;
            system("clear");
            printList(head);
            printf("Enter position to delete : ");
            scanf("%d",&pos);
            head=deleteAt(head,pos);
            printList(head);
        }
        else if(choice==4)
        {
            int data,pos;
            system("clear");
            printList(head);
            printf("Enter Data to insert : ");
            scanf("%d",&data);
            printf("Enter position to insert after: ");
            scanf("%d",&pos);
            head=insertAt(head,data,pos+1);
            printList(head);
        }
        else
        {
            break;
        }
    }
    
}