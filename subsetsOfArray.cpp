//Question : https://youtu.be/vk8sfizNtsY?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

//Solution : https://youtu.be/iKSI_9NHR1M?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

//NOTE : I have used a different approach than binary subsets generation 

#include<iostream>
#include<vector>
using namespace std;

void printSubsets(int arr[],int n,int i,vector<int> temp)
{
    if(i==n)
    {
        //I am not printing the empty subset
        if(!temp.empty())
        {   for(auto &it:temp)
            cout<<it<<" ";
            cout<<"\n";
        }
    }
    else
    {
        //we have 2 choices , either take or not take the element
        printSubsets(arr,n,i+1,temp);
        temp.push_back(arr[i]);
        printSubsets(arr,n,i+1,temp);
    }

}

int main()
{
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
    cin>>arr[i];
    vector<int> temp;
    printSubsets(arr,n,0,temp);
    
}