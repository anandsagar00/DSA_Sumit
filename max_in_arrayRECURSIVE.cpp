//This program finds maximum in an array , using recursion

#include<vector>
#include<iostream>
using namespace std;

int findMax(vector<int> &arr,int i,int n)
{
    if(i>=n)
    {
        return INT_MIN;
    }
    else
    {
        return max(arr[i],findMax(arr,i+1,n));
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n,-1);
    
    for(int i=0;i<n;i++)
    cin>>arr[i];

    cout<<"Max element in array is : "<<findMax(arr,0,n);
}