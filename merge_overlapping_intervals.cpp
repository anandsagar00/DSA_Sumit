//Question : https://youtu.be/XsOI7fpx8IY?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk
/*
Explanation : https://www.pepcoding.com/resources/online-java-foundation/stacks-and-queues/merge_overlapping_interval/topic
You are given a number n, representing the number of time intervals.
In the next n lines, you are given a pair of space-separated numbers.
The pair of numbers represents the start time and end time of a meeting
(the first number is the start time and the second number is end time)
You are required to merge the meetings and print the output of the merged meeting in increasing order of start time.
*/

// SOL : https://youtu.be/QlaDyZTCAbM?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

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
    int n;
    cin>>n;

    vector<pair<int,int> > arr(n);

    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        arr[i]=make_pair(a,b);
    }

    //First we will sort the array

    sort(arr.begin(),arr.end());

    stack<pair<int,int> > st;

    st.push(arr[0]);

    for(int i=1;i<n;i++)
    {
        /*
        We will check the current element of the sorted array with the top element of the stack
        and if there will be a overlapping interval we will merge it.
        */
       int t1=st.top().first;
       int t2=st.top().second;

       int t3=arr[i].first;
       int t4=arr[i].second;

       if(t3>=t1 && t3<=t2)
       {
            int t5=min(t1,t3);
            int t6=max(t2,t4);
            st.pop();
            st.push(make_pair(t5,t6));
       }
       else
       {
        st.push(arr[i]);
       }
    }
    vector<pair<int,int> > ans;

    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(),ans.end());
    // cout<<"ANS : \n";
    for(auto &el:ans)
    {
        cout<<el.first<<" "<<el.second<<"\n";
    }

}