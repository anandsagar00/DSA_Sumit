/*
Explanation : https://www.pepcoding.com/resources/online-java-foundation/stacks-and-queues/infix_conversion/topic

Question : https://youtu.be/Nfui0rgbQe8?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

In this problem you are provided with an infix expression and
you are required to convert it to postfix and prefix and print both these expressions.
You don't need to worry about input; it is already managed for you.

What are postfix and prefix expressions?
Postfix Expression:
When operator is post fixed to operands, i.e. operator is placed after operands.
For example: Infix expression: x*y
Postfix expression: xy*

Prefix Expression
When operator is prefixed to operands, i.e. operator is placed before operands.
For example: Infix expression: x*y
Prefix expression: *xy
Sample Input: 2 * ( 6 - 4 + 8 ) / 3
Sample Output: POSTFIX : 2 6 4 - 8 + * 3 /
PREFIX : / * 2 + - 6 4 8 3
*/

// Solution : https://youtu.be/f29emeUcw6c?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

// NOTE : Infix evaluation is must for this , as solving that will make these crystal clear

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <unordered_map>
#include <set>
#include <map>
#include <unordered_set>
#include <string>
#include <limits.h>
using namespace std;
#define ll long long int
const int mod = 1e9 + 7;

int getPriority(char op)
{
    // This function returns the priority of an operator
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else
        return 0;
}

bool isOperator(char op)
{
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '(' || op == ')')
        return true;
    else
        return false;
}

template <typename T>
void printStack(stack<T> s)
{
    //For Debugging
    while (!s.empty())
    {
        cout<<s.top()<<",";
        s.pop();
    }
    cout<<"\n";
}

int main()
{
    string exp;
    getline(cin, exp);

    stack<string> pre, post; // Two stacks to store prefix and postfix notation

    stack<char> oprtr; // Stack to store the operators

    // Steps are pretty much same as infix evaluation

    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];

        if (ch == ' ')
            continue;

        if (!isOperator(ch))
        {
            string temp = "";
            temp.push_back(ch);
            pre.push(temp);
            post.push(temp);
        }
        else
        {
            if (oprtr.empty() || ch == '(')
            {
                oprtr.push(ch);
            }
            else if (ch != ')')
            {
                while (!oprtr.empty() && oprtr.top() != '(' && getPriority(ch) <= getPriority(oprtr.top()))
                {
                    char op=oprtr.top();
                    oprtr.pop();
                    string op2 = pre.top();
                    pre.pop();
                    string op1 = pre.top();
                    pre.pop();

                    // FOR PREFIX
                    string temp1 = "";
                    temp1.push_back(op);
                    temp1 = temp1 + op1 + op2; // concatenating strings
                    pre.push(temp1);

                    string op4 = post.top();
                    post.pop();
                    string op3 = post.top();
                    post.pop();
                    // FOR POSTFIX
                    string temp2 = "";
                    temp2 = op3 + op4; // concatenating strings
                    temp2.push_back(op);
                    post.push(temp2);
                }
                oprtr.push(ch);
            }
            else
            {
                // This is a case where we find a closing bracket
                while (oprtr.top() != '(')
                {
                    char op = oprtr.top();
                    oprtr.pop();
                    string op2 = pre.top();
                    pre.pop();
                    string op1 = pre.top();
                    pre.pop();

                    // FOR PREFIX
                    string temp1 = "";
                    temp1.push_back(op);
                    temp1 = temp1 + op1 + op2; // concatenating strings
                    pre.push(temp1);

                    string op4 = post.top();
                    post.pop();
                    string op3 = post.top();
                    post.pop();
                    // FOR POSTFIX
                    string temp2 = "";
                    temp2 = temp2 + op3 + op4; // concatenating strings
                    temp2.push_back(op);
                    post.push(temp2);
                }
                oprtr.pop();//to remove the '('
            }
        }
    }
    while (!oprtr.empty())
    {
        char op = oprtr.top();
        oprtr.pop();
        string op2 = pre.top();
        pre.pop();
        string op1 = pre.top();
        pre.pop();

        // FOR PREFIX
        string temp1 = "";
        temp1.push_back(op);
        temp1 = temp1 + op1 + op2; // concatenating strings
        pre.push(temp1);

        string op4 = post.top();
        post.pop();
        string op3 = post.top();
        post.pop();
        // FOR POSTFIX
        string temp2 = "";
        temp2 =op3 + op4; // concatenating strings
        temp2.push_back(op);
        post.push(temp2);
    }
    // cout << "PREFIX : " << pre.top() << "\nPOSTFIX : " << post.top() << "\n";
    cout <<post.top() << "\n" << pre.top() << "\n";
}