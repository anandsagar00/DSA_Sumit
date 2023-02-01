// Question : https://youtu.be/d42uDPBOXSw?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

//Solution : https://youtu.be/Zobz9BXpwYE?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

#include<vector>
#include<limits.h>
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

   dp[n]=0;

   for(int i=n-1;i>=0;i--)
   {
        int jmp=jumps[i];

        int min_moves=99999;//Fairly large number which might not be the number of jumps
        for(int j=1;j<=jmp;j++)
        {
            if(i+j<=n)
            min_moves=min(min_moves,dp[i+j]);
        }

        dp[i]=1+min_moves;
   }
   cout<<dp[0]<<"\n";
}