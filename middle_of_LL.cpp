//Middle of a linked List , in single pass , w/o getting the size of the LL 

/*
Note :  There are two ways in which you define mid in case of list with even no. of elements

way1 : 1->2->3->4
       Middle Element = 2

way2 : 1->2->3->4
       Middle Element = 3

I've done using way1 , in case of way1 initialise first ptr to head and 2nd to head->next
in case of way2 initialise both to head 

Way2 can be found in prev commit
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

int main()
{
    Node *head=NULL;
    head=input();

    cout<<"\nThe list inputted was : \n";
    printList(head);

    //using 2 pointer algorithm , move one pointer by one and another by 2

    Node *p=head;
    Node *q=head->next;

    while(q!=NULL && q->next!=NULL)
    {
        p=p->next;
        q=q->next->next;
    }

    cout<<"\nMiddle of the inputted linked list was : "<<p->data<<"\n";

}