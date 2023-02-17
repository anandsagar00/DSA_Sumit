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
const int mod=1e9+7;

/*
This question was asked in paypal interview , you are given a list of commonly used password and
a list of passwords , now you have to classify the passwords as weak or strong , the conditions are : 

Condition for a password to be weak is : 

1. password is less than 6 characters
2. password has all CAPITAL characters
3. password has all small characters
4. password has all digits
5. any substring of password should not be in commonly used passwords

*/

vector<string> generateSubsets(string s)
{
    //This function generates subsets [Note : we are not using it anywhere]
    int n=s.length();
    long long int bit=1<<n;

    vector<string> ans;

    for(int i=0;i<=bit;i++)
    {
        string temp="";
        int ci=i;
        int j=0;
        while(ci>0)
        {
            if(ci&1)
            temp.push_back(s[j]);
            j++;
            ci=ci>>1;
        }
        ans.push_back(temp);
    }
    return ans;
}

vector<string> getSubstrings(string s) {
    vector<string> substrings;

    for (int i = 0; i < s.length(); i++) {
        for (int j = 1; j <= s.length() - i; j++) {
            string substring = s.substr(i, j);
            substrings.push_back(substring);
        }
    }

    return substrings;
}

vector<string> getPasswordStrength(vector<string> passwords,vector<string> common_words)
{
    sort(common_words.begin(),common_words.end());
    vector<string> ans;
    for(auto &password:passwords)
    {
        bool flag=false; //by default strong

        if(password.size()<6)
        {
            flag=true;
        }

        bool flag_all_long=true;
        for(auto &letter:password)
        {
            if(!(letter>='A' && letter<='Z'))
            {
                flag_all_long=false;
                break;
            }
        }
        bool flag_all_short=true;
        for(auto &letter:password)
        {
            if(!(letter>='a' && letter<='z'))
            {
                flag_all_short=false;
                break;
            }
        }
        bool flag_all_digit=true;
        for(auto &letter:password)
        {
            if(!(letter>='0' && letter<='9'))
            {
                flag_all_digit=false;
                break;
            }
        }

        if(flag_all_long || flag_all_short || flag_all_digit)
        {
            flag=true;
        }

        vector<string> subsets=getSubstrings(password);

        for(auto &words:subsets)
        {
            if(words!="" && binary_search(common_words.begin(),common_words.end(),words))
            {
                flag=true;
                break;
            }
        }

        if(flag)
        ans.push_back("weak");
        else
        ans.push_back("strong");

    }
    return ans;
}

int main()
{
    vector<string> p,cw,ans;
    int n,m;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        p.push_back(s);
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        string s;
        cin>>s;
        cw.push_back(s);
    }
    ans=getPasswordStrength(p,cw);
    for(auto &words:ans)
    cout<<words<<"\n";
}