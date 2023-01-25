
// https://youtu.be/o4lZ5M87m7o?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk


#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int st=n/2+1;
    int sp=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=st;j++)
        cout<<"*";
        for(int k=1;k<=sp;k++)
        cout<<" ";
        for(int j=1;j<=st;j++)
        cout<<"*";
        cout<<"\n";

        if(i<=n/2)
        {
            st--;
            sp+=2;
        }
        else
        {
            sp-=2;
            st++;
        }
    }
}
