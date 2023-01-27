/*
Question : https://www.pepcoding.com/resources/online-java-foundation/stacks-and-queues/largest_area_histogram/topic
You are given a number n, representing the size of array a.
You are given n numbers, representing the height of bars in a bar chart.
You are required to find and print the area of the largest rectangle in the histogram.
*/

// Solution : https://youtu.be/0do2734xhnU?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

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
    vector<int> arr(n,-1);

    for(int i=0;i<n;i++)
    cin>>arr[i];

    /*
    We will have to find the next smaller element as well as prev smaller elements
    that way we will be able to get the maximum rectangle out of a single bar
    Video of what I am saying : https://youtu.be/0do2734xhnU?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&t=75
    */

   vector<int> NSE(n,-1);//vectors which will store Next Smaller as well as prev smaller element's index
   vector<int> PSE(n,-1);

   stack<int> st1,st2;

   for(int i=0;i<n;i++)
   {
        if(st1.empty())
        {
            st1.push(i);
        }
        else
        {
            while(!st1.empty() && arr[i]<arr[st1.top()])
            {
                NSE[st1.top()]=i;
                st1.pop();
            }
            st1.push(i);
        }

        if(st2.empty())
        {
            st2.push(i);
        }
        else
        {
            while(!st2.empty() && arr[i]<=arr[st2.top()])
            {
                st2.pop();
            }

            if(!st2.empty())
            PSE[i]=st2.top();
            st2.push(i);
        }
   }
    int largest_area=-1;
   for(int i=0;i<n;i++)
   {    
        //The stmt below is to see that the prev smaller el , and NSE index is correct or not
        // DEBUG : cout<<"( "<<PSE[i]<<","<<" "<<NSE[i]<<" ) ,";
        int length=arr[i];
        int width=(NSE[i]-PSE[i]-1);

        if(NSE[i]==-1 && PSE[i]==-1)//if there is no any PSE or NSE
        width=n;

        largest_area=max(largest_area,length*width);
   }
    cout<<largest_area<<"\n";
}