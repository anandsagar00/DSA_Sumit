// https://youtu.be/K5xJXbnYMBc?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

//Solution : 

#include<vector>
#include<string>
#include<iostream>

using namespace std;

void permutations(string s,vector<bool> visited,vector<string> &v,string temp)
{
    if(temp.length()==s.length())
    {
        v.push_back(temp);
    }
    else
    {
        for(int i=0;i<s.length();i++)
        {
            if(!visited[i])
            {
                visited[i]=true;
                permutations(s,visited,v,temp+s[i]);
                visited[i]=false;
            }
        }
    }
}

int main()
{
    string s;
    cin>>s;
    vector<string> v;

    vector<bool> visited(s.length(),false);

    permutations(s,visited,v,"");

    cout<<"PERMUTATIONS OF "<<s<<" are : \n\n";
    for(auto &words:v)
    cout<<words<<"\n";
}