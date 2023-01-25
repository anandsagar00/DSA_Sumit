// https://youtu.be/P97Ms8kSzjg?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

/*
1. You are required to display the prime factorization of a number.
    2. Take as input a number n.
    3. Print all its prime factors from smallest to largest.

    input : 1440
    output : 2 2 2 2 2 3 3 5
*/

#include<iostream>
using namespace std;

void printPrimeFactor(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            cout<<i<<" ";
            n/=i;
        }
    }
    if(n!=1)
    cout<<n<<"\n";
}

int main()
{
    int n;
    cin>>n;
    printPrimeFactor(n);
}