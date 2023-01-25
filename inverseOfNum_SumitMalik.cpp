//The Question Description can be found at the link below : 
// https://youtu.be/dbk42TKwk4M?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int new_num=0;

    int dig=1;
    while(n>0)
    {
        int position=n%10;

        int num_to_add=pow(10,position-1)*dig;

        new_num+=num_to_add;
        dig++;
        n/=10;
    }
    cout<<new_num<<"\n";

}