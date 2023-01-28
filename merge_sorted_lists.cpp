/*
You have been given two sorted linked list , merge both the linked list w/o using extra space so that
the resultin list is also a sorted one
*/

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

Node *mergeList(Node *head1,Node *head2)
{
    Node *p=head1;
    Node *q=head2;

    Node *r=NULL;
    Node *head3=NULL;

    while(p!=NULL && q!=NULL)
    {
        if(p->data<=q->data && r==NULL)
        {
            //this will be the head of the merged list
            r=p;
            p=p->next;
            r->next=NULL;
            head3=r;
        }
        else if(q->data<=p->data && r==NULL)
        {
            //this will be the head of the merged list
            r=q;
            q=q->next;
            r->next=NULL;
            head3=r;
        }
        else if(p->data<=q->data)
        {
            r->next=p;
            p=p->next;
            r=r->next;
            r->next=NULL;
        }
        else
        {
            r->next=q;
            q=q->next;
            r=r->next;
            r->next=NULL;
        }
    }
    while(p!=NULL)
    {
        r->next=p;
        p=p->next;
        r=r->next;
        r->next=NULL;
    }
    while(q!=NULL)
    {
        r->next=q;
        q=q->next;
        r=r->next;
        r->next=NULL;
    }
    return head3;
}

int main()
{
    Node *head1=NULL;
    Node *head2=NULL;

    head1=input();
    head2=input();

    cout<<"\nInputted list1 is : \n";
    printList(head1);
    cout<<"\nInputted list2 is : \n";
    printList(head2);

    Node *head3=NULL;
    head3=mergeList(head1,head2);

     printList(head3);

}