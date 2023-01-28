//Add Two numbers represented by a linked list

//Question : https://youtu.be/EmlJIS1K7tk?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

//Solution : https://youtu.be/tK4eez3syAQ

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
        cout<<p->data;
        p=p->next;
    }
    cout<<"\n";
}

int length(Node *head)
{
    int count=0;
    while(head!=NULL)
    {
        count++;
        head=head->next;
    }
    return count;
}

int addLists(Node *head1,Node *head2,int n1,int n2,Node *&head3)
{
    //We will always send the larger list as head1 and smaller as head2
    if(head1==NULL || head2==NULL)
    return 0;
    else
    {
        int carry=0,sum=0;
        if(n1>n2)
        {
            carry=addLists(head1->next,head2,n1-1,n2,head3);
            sum=carry+head1->data;
        }
        else
        {
            carry=addLists(head1->next,head2->next,n1-1,n2-1,head3);
            sum=carry+head1->data+head2->data;
        }

        Node *temp=new Node(sum%10);
        temp->next=head3;
        head3=temp;
        return sum/10;//this line returns the carry
    }
}

int main()
{
    Node *head1=input();
    Node *head2=input();

    cout<<"NUM1 ";
    printList(head1);
    cout<<"NUM2 ";
    printList(head2);

    int n1=length(head1);
    int n2=length(head2);

    Node *head3=NULL;

    if(n1>n2)
    {
        int carry=addLists(head1,head2,n1,n2,head3);
        if(carry!=0)
        {
            Node *temp=new Node(carry);
            temp->next=head3;
            head3=temp;
        }
    }
    else
    {
        int carry=addLists(head2,head1,n2,n1,head3);
        if(carry!=0)
        {
            Node *temp=new Node(carry);
            temp->next=head3;
            head3=temp;
        }
    }

    cout<<"SUM : ";
    printList(head3);


}