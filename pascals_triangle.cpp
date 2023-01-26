// https://youtu.be/zAnV4KZ6uDk?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int val=1;
        for(int j=0;j<=i;j++)
        {
            //We have to print : iCj
            // nCr+1=(nCr)*(n-r)/(r+1)
            cout<<val<<" ";
            val=(val*(i-j))/(j+1);
        }
        cout<<"\n";
    }
}