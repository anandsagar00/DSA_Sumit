// https://youtu.be/ysMHtDIlU0c?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

/*
1. You are given two numbers n and k. You are required to rotate n, k times to the right.
If k is positive, rotate to the right i.e. remove rightmost digit and make it leftmost.
Do the reverse for negative value of k. Also k can have an absolute value larger than number of digits in n.
2. Take as input n and k.
3. Print the rotated number.
4. Note - Assume that the number of rotations will not cause leading 0's in the result. e.g. such an input will not be given
   n = 12340056
   k = 3
   r = 05612340

   ex: n = 273516 , k=2 , ans = 162735
*/

//Solution : https://youtu.be/lt8oCGqYMGg?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    int cn=n;//copy of number
    int count_digits=0;

    while(n>0)
    {
        count_digits++;
        n/=10;
    }

    k=k%count_digits;

    if(k<0)
    k+=count_digits;

    int divisor=pow(10,k);

    int multiplier=pow(10,count_digits-k);

    int quotient=cn/divisor;
    int rem=cn%divisor;

    int first_part=multiplier*rem;

    int ans=first_part+quotient;

    cout<<ans<<"\n";

}