/*
You are given a string exp representing an expression.
Assume that the expression is balanced i.e. the opening and closing brackets match with each other.
There is always a closing bracket for each opening bracket.
But, some of the pairs of brackets may be extra/needless.
You are required to print true if you detect extra brackets and false otherwise.
Example

((a+b)+(c+d)) -> false: There is no redundant or duplicate braces found
(a+b)+((c+d)) -> true: There is a pair of redundant or duplicate braces around c+d.
*/

//https://youtu.be/aMPXhEdpXFA?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

#include<iostream>
#include<fstream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<utility>
#include<unordered_map>
#include<set>
#include<map>
#include<unordered_set>
#include<string>
#include<limits.h>
using namespace std;
#define ll long long int
const int mod=1e9+7;

bool checkDuplicateBracket(string &str)
{
    stack<char> st;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]!=')')
        st.push(str[i]);
        else
        {
            if(!st.empty())
            {
                if(st.top()=='(')
                return true;
                else
                {
                    while(st.top()!='(' && !st.empty())
                    st.pop();
                }
                if(!st.empty())
                st.pop();
            }
        }
    }
    return false;
}

int main()
{
    string s;
    cin>>s;

    bool ans=checkDuplicateBracket(s);

    if(ans)
    cout<<"true\n";
    else
    cout<<"false\n";

}