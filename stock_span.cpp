/*
Problem Link : https://www.pepcoding.com/resources/online-java-foundation/stacks-and-queues/stock_span/topic
You are given a number n, representing the size of array a.
You are given n numbers, representing the prices of a share on n days.
You are required to find the stock span for n days.
Stock span is defined as the number of days passed between 
the current day and the first day before today when the price was higher than today.
*/
/*
Note : NGE on left , Number of days b/w NGE on left and current number
*/

// Solution : https://youtu.be/0BsPlzqksZQ?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

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

    vector<int> arr(n,0);
    vector<int> NGE(n,-1);//This vector store the indices of Previous Greater Element

    for(int i=0;i<n;i++)
    cin>>arr[i];

    stack<int> st;

    for(int i=0;i<n;i++)
    {
        if(st.empty())
        {
            st.push(i);
        }
        else
        {
            while(!st.empty() && arr[st.top()]<=arr[i])
            st.pop();

            if(!st.empty())
            NGE[i]=st.top();

            st.push(i);
        }
    }
    
    for(int i=0;i<n;i++)
    {
        //This loop prints the span
        if(NGE[i]==-1)
        cout<<(i+1)<<"\n";
        else
        cout<<(i-NGE[i])<<"\n";
    }
}