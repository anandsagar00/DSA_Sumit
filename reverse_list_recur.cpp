//Question reverse a linked list using recursion

#include<iostream>
using namespace std ;

struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

Node *input()
{
    //number of nodes taking as input
    int n;
    cin>>n;

    Node *head=NULL;
    Node *tail=NULL;

    for(int i=0;i<n;i++)
    {
        //this is to take input of n nodes
        int x;
        cin>>x;
        Node *temp=new Node(x);

        if(head==NULL)
        {
            head=temp;
            tail=temp;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    }
    return head;
}

void printList(Node *head)
{
    Node *p=head;

    while(p!=NULL)
    {
        cout<<p->data<<" -> ";
        p=p->next;
    }
    cout<<"\n";
}

Node *rev(Node *head)
{
    //Function to reverse a linked list recursively
    if(head->next==NULL)
    return head;
    else
    {
        Node *temp=rev(head->next);
        Node *p=temp;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        head->next=NULL;
        p->next=head;
        head=temp;
        return head;
    }
}

int main()
{
    Node *head=input();

    cout<<"Original list : \n";
    printList(head);

    if(head!=NULL)
    head=rev(head);

    cout<<"Reversed list : \n";
    printList(head);
}