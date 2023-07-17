#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* getNode(int data)
{
    Node *temp=(Node*)malloc(sizeof(Node));
    temp->data=data;
    temp->next=NULL;

    return temp;
}

Node* append(Node *head,int data)
{
    if(head==NULL)
    {
        head=getNode(data);
        return head;
    }
    else
    {
        Node *p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=getNode(data);
        return head;
    }
}

Node* reverse(Node* head)
{
    Node *prev=NULL ;
    Node *curr=head;
    Node *next;

    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

Node* insertAt(Node *head,int data,int pos)
{
    if(pos==1)
    {
        Node* temp=getNode(data);
        temp->next=head;
        head=temp;
        return head;
    }
    else
    {
        int i=1;
        
        Node* p=head;

        while(p!=NULL && i<pos)
        {
            if(i==pos-1)
            {
                Node* newNode=getNode(data);
                Node *temp=p->next;
                p->next=newNode;
                newNode->next=temp;
                return head;
            }
            i++;
            p=p->next;
        }

    }
    return head;
}

Node* deleteAt(Node* head,int pos)
{
    if(head==NULL)
    return head;

    if(pos==1)
    {
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    else
    {
        int i=1;
        Node *curr=head;
        Node *prev=NULL;
        while(curr!=NULL && i<=pos)
        {
            if(i==pos)
            {
                prev->next=curr->next;
                free(curr);
                return head;
            }
            i++;
            prev=curr;
            curr=curr->next;
        }
    }
    return  head;
}

void printList(Node *head)
{
    while(head!=NULL)
    {
        printf("%d - > ",head->data);
        head=head->next;
    }
    printf("\n");
}

int main()
{
    Node* head=NULL;
    while (1)
    {
        int choice;
        printf("Press 1 to append .\nPress 2 to insert at given position.\nPress 3 to delete at given position\nPress 4 to insert after a given position\nPress 5 to reverse list\nPress any other key to exit.\n");
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
        else if(choice==5)
        {
            system("clear");
            printf("OLD LIST : ");
            printList(head);
            printf("REVERSED LIST : ");
            head=reverse(head);
            printList(head);
        }
        else
        {
            break;
        }
    }
    
}