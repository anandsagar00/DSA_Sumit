//Question : https://youtu.be/BhYvZ4kVaug?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

/*
Explanation : https://www.pepcoding.com/resources/online-java-foundation/stacks-and-queues/minimum_stack_2_constant_space/topic
The previous problem required us to make a minimum stack using constant time.
However this question demands to do it in constant space.
*/

// Solution : https://youtu.be/Trz7JM610Uc?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

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
    min of all elements present in the stack now in constant time O(1) and constant space
    */

   /*
   Logic : 
   */

  stack<int> st;

  while(1)
  {
    //Menu Driven Program
    cout<<"Press 1 to push.\n";
    cout<<"Press 2 to pop.\nPress 3 to find min.\nPress any other keys to exit.\n";

    int ch;
    cin>>ch;

    //TODO : 
  }
}