// https://youtu.be/ysMHtDIlU0c?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

//My This solution works for Input with non-zero digits and inputs which are +ve

//Rotate a number by K digits

/*
27391 becomes 91 273 , after rotation when k=2
*/

#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    int left=0,right=0;

    int copyN=n;

    int pow1=1,pow2=1;

    int count_digits=0;

    while(copyN>0)
    {
        count_digits++;
        copyN/=10;
    }

    k=k%count_digits;
    int copyK=k;
    copyN=n;

    while(copyN>0)
    {
        if(copyK>0)
        {
            right=(pow1*(copyN%10))+right;
            pow1*=10;
        }
        else
        {
            left=(pow2*(copyN%10))+left;
            pow2*=10;
        }
        copyK--;
        copyN/=10;
    }

    int ans=(right*pow(10,count_digits-k))+left;

    cout<<ans<<"\n";

}