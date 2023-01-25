// https://youtu.be/4wtESDtEBp4?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

//To count number of digits in an integer

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int count=0;
    while(n>0)
    {
        count++;
        n/=10;
    }
    cout<<count<<"\n";
}