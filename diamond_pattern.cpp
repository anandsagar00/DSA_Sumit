// https://youtu.be/uKND5Sc2QzQ?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

//N will always be odd

/*
For N=5

  *
 ***
*****
 ***
  *

*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int sp=n/2;
    int st=1;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=sp;j++)
      cout<<" ";
      for(int k=1;k<=st;k++)
      cout<<"*";
      cout<<"\n";
      if(i<=n/2)
      {
        sp--;
        st+=2;
      }
      else
      {
        sp++;
        st-=2;
      }
    }
}