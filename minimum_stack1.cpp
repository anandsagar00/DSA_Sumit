//Question : https://youtu.be/NslJ5PXAM4Q?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

/*
Explanation : https://www.pepcoding.com/resources/online-java-foundation/stacks-and-queues/minimum_stack_1/topic
Here we are required to code a function min which should return the smallest element available in the stack and if not available return -1 after
printing "Stack underflow" in constant time i.e. time complexity should be O( 1 ).

The basic logic for the rest of the functions like pop( ), push( ), size( ),top( ) remains as it was with some minor modifications.
*/

//Solution : https://youtu.be/4bjCEJmiPZA?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

#include<iostream>
#include<fstream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<utility>
#include<unordered_map>
#include<set>
#include<map>
#include<unordered_set>
#include<string>
#include<limits.h>
using namespace std;
#define ll long long int
const int mod=1e9+7;

int main()
{
    /*
    All operations are same as normal stack , we have to implement an extra function which returns
    min of all elements present in the stack now in constant time O(1)
    */

   /*
   Logic : Maintain 2 stacks , one is normal and the other (min_stack) which stores only the elements 
   which are smaller than the top element of min_stack
   */

  stack<int> st,min_stack;

  while(1)
  {
    //Menu Driven Program
    cout<<"Press 1 to push.\n";
    cout<<"Press 2 to pop.\nPress 3 to find min.\nPress any other keys to exit.\n";

    int ch;
    cin>>ch;

    if(ch==1)
    {
        //Push
        int x;
        cin>>x;
        st.push(x);
        cout<<"\nPushed : "<<x<<"\n";
        if(min_stack.empty() || x<=min_stack.top())
        {
            min_stack.push(x);
        }
    }
    else if(ch==2)
    {
        if(!st.empty())
        {
            int tp=st.top();
            if(tp==min_stack.top())
            {
                min_stack.pop();
                st.pop();
            }
            else
            st.pop();
            cout<<"\nPopped : "<<tp<<"\n";
        }
        else
        cout<<"\nEmpty Stack\n";
    }
    else if(ch==3)
    {
        cout<<"\nMinimum Element is : "<<min_stack.top()<<"\n";
    }
    else
    {
        cout<<"\nEXIT\n";
        break;
    }
  }
}