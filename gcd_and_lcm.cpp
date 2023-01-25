// https://youtu.be/8RlrYFljNJI?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

// 1. You are required to print the Greatest Common Divisor (GCD) of two numbers.
// 2. You are also required to print the Lowest Common Multiple (LCM) of the same numbers.
// 3. Take input "num1" and "num2" as the two numbers.
// 4. Print their GCD and LCM.

#include<iostream>
using namespace std;

int gcd(int dividend,int divisor)
{
    //recursive function to calculate GCD
    if(dividend%divisor==0)
    return divisor;

    return gcd(divisor,dividend%divisor);
}

int main()
{
    int num1,num2;
    cin>>num1>>num2;

    int g=gcd(num1,num2);
    int lcm=(num1*1LL*num2)/g; // we know LCM=(product of 2 number)/gcd
    cout<<"GCD : "<<g<<" , LCM : "<<lcm<<"\n";
}
