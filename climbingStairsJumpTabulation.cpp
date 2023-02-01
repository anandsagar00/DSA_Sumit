//Video at current time is very imp : https://youtu.be/uNqoQ0sNZCM?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&t=176

//Explanation : https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/climb_stairs_with_variable_jumps/topic

//The input in the array represents the maximum number of jumps that we can take from that step
#include<vector>
#include<iostream> 

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> jumps(n,0); 

    for(int i=0;i<n;i++)
    cin>>jumps[i];
    
    vector<int> dp(n+1,-1);
    
    // We will solve this question by tabulation , the recursive+memoization has been already solved

    /*
        1.  Storage and Meaning 
        2.  Direction
        3.  Travel and Solve
    */

   dp[n]=1;

   for(int i=n-1;i>=0;i--)
   {
        int jmp=jumps[i];

        int total_ways=0;
        for(int j=1;j<=jmp;j++)
        {
            if(i+j<=n)
            total_ways+=dp[i+j];
        }

        dp[i]=total_ways;
   }
   cout<<dp[0]<<"\n";
}