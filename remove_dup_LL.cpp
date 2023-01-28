/*
Question : https://youtu.be/T4Od7rqE2BM?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk
Explanation : https://www.pepcoding.com/resources/online-java-foundation/linked-lists/remove_duplicates_in_sorted_linked_list/topic

You are given a partially written LinkedList class.
You are provided with a sorted linked list.
The function must remove all duplicates from the list in linear time and constant space.
Note: We can modify the original linked list to achieve constant space solution.


Example:
For the linked list: 1 -> 2 -> 2 -> 3 -> 3 -> 3 -> 5 -> 6 -> 6 -> null, the resultant linked list with no duplicates will be: 1 -> 2 -> 3 -> 5 -> 6 -> null.
*/

// Solution : https://youtu.be/ErSDF5IM1fo?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk


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
    Node *head=input();

    cout<<"\nThe Input list was : \n";
    printList(head);

    Node *new_head=NULL;

    Node *p=head;//to point to old list
    Node *q=NULL;//to point to new list

    while(p!=NULL)
    {
        if(q==NULL)
        {
            q=new Node(p->data);
            new_head=q;
            q->next=NULL;
        }
        else
        {
            if(p->data!=q->data)
            {
                Node *temp=new Node(p->data);
                q->next=temp;
                q=q->next;
            }
        }
        p=p->next;
    }

    cout<<"\nList without duplicate is : \n";
    printList(new_head);
}