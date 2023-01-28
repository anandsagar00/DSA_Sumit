// Question : https://youtu.be/Ko3DktYG4zs?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

/*
Explanation : https://www.pepcoding.com/resources/online-java-foundation/linked-lists/k_reverse_in_linked_list%20/topic
You are given a partially written LinkedList class. (Input and Output is managed for you.)
You are required to complete the body of the kReverse function.
The function is expected to tweak the list such that all groups of k elements in the list get reversed and linked.
If the last set has less than k elements, leave it as it is (don't reverse).
*/

// Solution : https://youtu.be/jhm2pYGFIos?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

//Note : This is one of the best and easiest solutions

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
    //TODO : 
}