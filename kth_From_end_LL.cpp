// Question : https://youtu.be/cEJoiG9Gn_k?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk
/*
We have a linked list of integers and we are also given an integer "k".
We have to find the "kth" node from the end of the linked list.
The index of the first node is 0. 

For instance, we are given k=2. So, we had to return the second element from the end of the linked list (i.e. if the last element has index=0,
we have to return the element with index=2). We have to return 7 as it is the second element from the end of the linked list. Also, there are 3 constraints.

You have to solve this question using iteration
You do not have to use the size property of the linked list directly
or indirectly meaning you cannot use the available size function or size variable
and you are not allowed to calculate the size of the linked list either.
You have to solve this problem without knowing the size of the linked list.
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

    //Assumption : K will always be less than List length

    int k;
    cin>>k;

    int ck=k;
    Node *p=head;

    /*
    Logic : two pointer approach , take a pointer displace it k times ahead 
    */

    while(k--)
    {
        p=p->next;
    }

    Node *q=head;

    while(p!=NULL)
    {
        p=p->next;
        q=q->next;
    }

    cout<<"\nThe input list is : \n";
    printList(head);
    
    cout<<"\n"<<ck<<" th element from end is : "<<q->data<<"\n";

}