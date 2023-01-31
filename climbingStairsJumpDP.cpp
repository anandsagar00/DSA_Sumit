//Video : https://youtu.be/uNqoQ0sNZCM?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

//Explanation : https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/climb_stairs_with_variable_jumps/topic

//The input in the array represents the number of jumps that we can take from that step
#include<vector>
#include<iostream>

using namespace std;

int ways(int i,vector<int> &dp,vector<int> &jumps)
{
    if(i==jumps.size())
    return 1;
    else if(i>jumps.size())
    return 0;
    else if(dp[i]!=-1)
    return dp[i];
    else
    {
        int total=0;
        for(int j=1;j<=jumps[i];j++)
        {
            total+=ways(i+j,dp,jumps);
        }
        dp[i]=total;
        return dp[i];
    }
}

int main()
{
    int n;
    cin>>n;

    vector<int> jumps(n,0);

    for(int i=0;i<n;i++)
    cin>>jumps[i];
    
    vector<int> dp(n+1,-1);
    cout<<ways(0,dp,jumps);
}