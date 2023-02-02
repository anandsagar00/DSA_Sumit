// https://youtu.be/85gIj4eBdBA?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

#include<iostream>
using namespace std;

int find_max(int arr[],int n)
{
    int ans=arr[0]; 
    for(int i=0;i<n;i++)
    ans=max(ans,arr[i]);

    return ans;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];

    int mx=find_max(arr,n);

    int cols=n;
    int rows=mx;

    for(int i=rows;i>=1;i--)
    {
        for(int j=0;j<cols;j++)
        {
            if(arr[j]==i)
            {
                cout<<"**\t";
                arr[j]--;
            }
            else
            cout<<" \t";
        }
        cout<<"\n";
    }
}