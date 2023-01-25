// https://youtu.be/sVdGn8xfCCM?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

//Check for prime in Range [Naive Method]

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

bool checkPrime(int n)
{
    //this function checks for prime

    if(n==1)
    return false;

    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        return false;
    }
    return true;
}

int main()
{
    int low,high;
    cin>>low>>high;

    for(int i=low;i<=high;i++)
    {
        if(checkPrime(i))
        cout<<i<<" ";
    }
}