//Print all sub-arrays of an array

//Question link : https://youtu.be/YrE8E1J_rp4?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

//Solution link : 

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
    cin>>arr[i];

    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            for(int k=i;k<=j;k++)
            cout<<arr[k]<<"\t";
            cout<<"\n";
        }
    }
}