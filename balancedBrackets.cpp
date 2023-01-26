/*
1. You are given a string exp representing an expression.
2. You are required to check if the expression is balanced
i.e. closing brackets and opening brackets match up well.

e.g.
[(a+b)+{(c+d)*(e/f)}] -> true
[(a + b) + {(c + d) * (e / f)]} -> false
[(a + b) + {(c + d) * (e / f)} -> false
([(a + b) + {(c + d) * (e / f)}] -> false
*/

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

bool isBalanced(string &str)
{
    stack<char> st;
    for(int i=0;i<str.size();i++)
    {
        char ch=str[i];
        if(ch=='(' || ch=='{' || ch=='[')
        {
            st.push(ch);
        }
        else if(ch==')' || ch=='}' || ch==']')
        {
            if(!st.empty())
            {
                if(ch==')' && st.top()!='(')
                return false;
                else if(ch=='}' && st.top()!='{')
                return false;
                else if(ch==']' && st.top()!='[')
                return false;
                st.pop();
            }
            else
            return false;
        }
    }
    if(!st.empty())
    return false;
    return true;
}

int main()
{
    string s;
    getline(cin,s);
    if(isBalanced(s))
    cout<<"true\n";
    else
    cout<<"false\n";
}