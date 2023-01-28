//Prereq : Reverse Data Recursive , https://youtu.be/aL3l2-S9koY?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

// Question : Check if a list is pallindrome or not 

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

Node *Left;

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

bool checkPallindrome(Node *head,int size,int currPointing)
{
    if(head==NULL)
    return true;
    else
    {
        bool tillNow=checkPallindrome(head->next,size,currPointing+1);

        if(tillNow==false)
        return false;

        if(currPointing>size/2)//this condn because after half both the ptrs will cross each other and 
        {                      // and will have same impact
            if(Left->data!=head->data)
            return false;
        }
        Left=Left->next;
        return true;
    }
}

bool check(Node *head,int size)
{
    Left=head;
    return checkPallindrome(head,size,1);
}

int main()
{
    Node *head=input();

    cout<<"Input List : \n";
    printList(head);

    // We will use the idea of Reverse Data Recursive [Code not in this folder 28-01-2023]
    // but you can find the video explanation here : https://youtu.be/aL3l2-S9koY?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

    int size=0;

    Node *p=head;
    while(p!=NULL)
    {
        size++;
        p=p->next;
    }

    if(check(head,size))
    {
        cout<<"Pallindrome\n";
    }
    else
    cout<<"Not-Pallindrome.\n";

}