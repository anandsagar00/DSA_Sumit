/*
Explanation : https://www.pepcoding.com/resources/online-java-foundation/stacks-and-queues/celebrity_problem/topic

Question : https://youtu.be/iHM1FPLGcsU?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

Solution : https://youtu.be/CiiXBvrX-5A?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

You are given a number n, representing the number of people in a party.
You are given n strings of n length containing 0's and 1's. If there is a '1' in ith row and jth spot, then person i knows about person j.
A celebrity is defined as somebody who knows no other person but everybody else knows him.
Please don't consider whether a person knows himself/herself or not! In reality, everyone should know who they are and what their purpose in life is.
Print the indices of all the celebrities in the party, and there is no celebrity, then print "none".
Note: There will be at least 2 people in the party, i.e. N >= 2. A party with only the party organizer does not make sense, isn't it?

Example:
Consider a party of 4 people: with the array of strings as:

0000
1011
1101
1110

*/

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

// NOTE:ELIMINATION APPROACH : IF IN A PAIR IF ONE KNOWS THE OTHER THEN THAT PERSON IS GUARANTEED NOT A CELEB

int main()
{
    int n;
    cin>>n;

    stack<int> st;

    vector<vector<char>> arr(n,vector<char>(n,0));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cin>>arr[i][j];

        st.push(i);
        
    }
    while(st.size()>1)
    {
        int p1=st.top();
        st.pop();
        int p2=st.top();
        st.pop();

        if(arr[p1][p2]=='1')//that means p1 knows p2 , so p1 can never be a celeb , as celeb doesn't know anyone
        st.push(p2);
        else
        st.push(p1);

    }

    int final_candidate=st.top();//He is a final candidate , but for that also we will have to check
                                 //if everyone knows him or not
    st.pop();

    int flag=0;//flag to denote not a celeb

    for(int i=0;i<n;i++)
    {
        if(i==final_candidate)
        continue;

        if(arr[i][final_candidate]=='0' || arr[final_candidate][i]=='1')
        {
            flag=1;
            break;
        }
    }

    if(flag==1)
    cout<<"none\n";
    else
    {
        cout<<final_candidate<<"\n";
    }

}