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

vector<string> getSubstrings(string s) {

    //this function takes a string and returns all its substrings
    vector<string> substrings;

    for (int i = 0; i < s.length(); i++) {
        for (int j = 1; j <= s.length() - i; j++) {
            string substring = s.substr(i, j);
            substrings.push_back(substring);
        }
    }
    for(auto &subs:substrings)
    cout<<subs<<"\n";
    return substrings;
}

int main()
{
    getSubstrings("abcd");
}