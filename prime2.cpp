// https://youtu.be/HXSfAyjWM8A?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&t=469

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
    //This is a better than the previous one 

    int n;
    cin>>n; // To Check if n is prime or not

    int count=0;

    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            count++;
            break; // when the first number also divided then it is not prime
        }
    }

    if(count==0 && n!=1)
    cout<<"Prime\n"; 
    else
    cout<<"Not-Prime\n";

}