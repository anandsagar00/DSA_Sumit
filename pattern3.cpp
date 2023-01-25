// https://youtu.be/ArnoqgUbN8I?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        for(int sp=1;sp<=n-i;sp++)
        cout<<"\t";

        for(int st=1;st<=i;st++)
        cout<<"*\t";

        cout<<"\n";
    }

}