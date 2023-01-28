//Reverse a Linked List [OPTIMISED]

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

void reverseList(Node* &head)
{
    //This is an optimised (both space and time) method as this reverses links 
    Node *prev=NULL;
    Node *curr=head;
    Node *next;
    while(curr!=NULL)
    {
        next=curr->next;
        
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}

int main()
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
    reverseList(head);
    printList(head);
}