//Video : https://youtu.be/A6mOASLl2Dg?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

//Explanation : https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/climb_stairs/topic

#include<vector>
#include<iostream>

using namespace std;

int ways(int n,vector<int> &dp)
{
    if(n<0)
    return 0;
    else if(n==0)
    return 1;
    else if(dp[n]!=-1)
    return dp[n];
    else
    {
        dp[n] = ways(n-1,dp)+ways(n-2,dp)+ways(n-3,dp);
        return dp[n];
    }
}

int main()
{
    int n;
    cin>>n;
    
    vector<int> dp(n+1,-1);
    cout<<ways(n,dp);
}