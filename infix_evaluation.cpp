/*
Question : https://youtu.be/cv_kPZnMxdA?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk
In this problem it is given that you will be provided with an infix expression and you are required to evaluate and print it's value.You don't need to worry about input; it is already managed for you.

But what is even an infix expression?:
An infix expression is a single letter, or an operator, proceeded by one infix string and followed by another infix string.
x
x + y
(x + y) * (a - b) Basically it's just a fancy word for an algebraic expression which we have been studying since sixth or seventh grade. Only differences will be seen while solving these expressions because in this problem we will be considering the given constraints.
However there are also expressions called prefix and postfix expressions regarding which, we will be solving problems as we move further in this module. And those expressions are not in the form of a simple algebraic expression. We will deal with those problems only, not now.
Sample Input: 2 + 6 * 4 / 8 - 3
Sample Output: 2
You can also watch the question video of this problem to understand WHAT part of the question in a clearer way.
*/
// Solution : https://youtu.be/IY0nZLEg6MA?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

// Note : Looks very big but is very very simple

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

int solve(int op1, int op2, char op)
{
    if (op == '+')
    {
        return (op1 + op2);
    }
    else if (op == '-')
    {
        return (op1 - op2);
    }
    else if (op == '*')
    {
        return (op1 * op2);
    }
    else
    {
        return (op1 / op2);
    }
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

    // Lower priority operators will pop the higher or equal priority operators from stack and will get it solved
    // Link of What I am trying to say : https://youtu.be/IY0nZLEg6MA?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&t=266

    /*
    Jab bhi koi operator aata hai to wo khud se bare ya barabar priority wale elements ko khud se pahle
    solve karwa deta hai
    */

    // Closing bracket tab tak pop karwata hai jab tak opening bracket na mil jaye

    stack<int> operand;
    stack<char> oprtr;

    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == ' ')
            continue;

        /*DEBUG :
        cout<<"Operand : ";
        printStack(operand);
        cout<<"Operator : ";
        printStack(oprtr);
        cout<<"\n";*/

        char ch = exp[i];

        if (!isOperator(ch))
        {
            //DEBUG : cout<<"\n("<<ch<<","<<ch-'0'<<")"<<"\n";
            operand.push(ch - '0');
        }
        else
        {
            //DEBUG : cout<<"\n("<<ch<<","<<ch-'0'<<")"<<"\n";
            if (oprtr.empty() || ch == '(')
                oprtr.push(ch);
            else if (oprtr.top() != '(' && ch != ')' && getPriority(ch) <= getPriority(oprtr.top()))
            {
                
                int op2 = operand.top();
                operand.pop();
                int op1 = operand.top();
                operand.pop();

                char op = oprtr.top();
                oprtr.pop();

                operand.push(solve(op1,op2,op));

                oprtr.push(ch);
            }
            else if (ch != ')')
            {
                oprtr.push(ch);
            }
            else if (ch == ')')
            {
                // pop all and solve until you find opening bracket '('
                while (oprtr.top() != '(')
                {
                    int op2 = operand.top();
                    operand.pop();
                    int op1 = operand.top();
                    operand.pop();

                    char op = oprtr.top();
                    oprtr.pop();

                    operand.push(solve(op1,op2,op));
                }
                oprtr.pop();//this will pop the (
            }
        }
    }
    while (!oprtr.empty())
    {
        /*DEBUG :cout<<"Operand : ";
        printStack(operand);
        cout<<"Operator : ";
        printStack(oprtr);
        cout<<"\n";
        */
        int op2 = operand.top();
        operand.pop();
        int op1 = operand.top();
        operand.pop();

        char op = oprtr.top();
        oprtr.pop();

        operand.push(solve(op1,op2,op));
    }
    cout << operand.top() << "\n";
}