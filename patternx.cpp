// https://youtu.be/zcoVmVMIymQ?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j || (i+j)==n-1)
            cout<<"*";
            else
            cout<<" ";
        }
        cout<<"\n";
    }

}