// Question : https://youtu.be/zNxDJJW40_k?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

//Explanation : https://www.pepcoding.com/resources/online-java-foundation/recursion-backtracking/target_sum_subsets/topic

//Solution : https://youtu.be/HGDmj5NrrjM?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

//NOTE : Negative number may also be given in input

#include<iostream>
#include<vector>

using namespace std;

void targetSum(vector<int> &arr,int i,vector<vector<int> > &ans,vector<int> temp,int currentSum,int target)
{
    if(i>arr.size())
    {
        return;
    }
    else if(i==arr.size())
    {
        if(currentSum==target)
        {
            ans.push_back(temp);
        }
    }
    else
    {
        //we have 2 choices , either to include the current number or not include

        //Not-Include
        targetSum(arr,i+1,ans,temp,currentSum,target);

        //include
        temp.push_back(arr[i]);
        targetSum(arr,i+1,ans,temp,currentSum+arr[i],target);
    }
    
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int target;
    cin>>target;

    vector<vector<int> > ans;
    vector<int> temp;
    targetSum(arr,0,ans,temp,0,target);

    for(auto &v:ans)
    {
        for(auto &nums:v)
        cout<<nums<<" ";
        cout<<"\n";
    }
}