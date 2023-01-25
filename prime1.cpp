// https://www.youtube.com/watch?v=3bCf5xSVkbo&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=11&ab_channel=Pepcoding

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
    //This is the most naive method to check for prime
    int n;
    cin>>n;//check if n is prime or not

    int count_factors=0;

    for(int i=2;i<n;i++)
    {
        if(n%i == 0)
        count_factors++;
    }

    if(count_factors==0 && n!=1)
    cout<<"Prime\n";
    else
    cout<<"Not-Prime";

}