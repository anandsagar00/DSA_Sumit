// https://youtu.be/JbLEpRy_vTk?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

//To print all Fibonacci numbers till N 

#include<iostream>
#include<fstream>
#include<vector>
#include<iterator>
#include<algorithm>
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

int main()
{
    int n;
    cin>>n;

    int first=1,second=1;

    if(n==1)
    cout<<"1 ";
    if(n>=2)
    cout<<"1 1 ";

    for(int i=3;i<=n;i++) // This loop runs for n-2 times as 2 have already been taken care of
    {
        int current=first+second;
        cout<<current<<" ";
        
        first=second;
        second=current;
    }

}

