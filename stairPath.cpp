//Question : https://youtu.be/W6cT68K7Hls?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk
//Explanation : https://www.pepcoding.com/resources/online-java-foundation/recursion-with-arraylists/get_stair_paths/topic

//Solution : https://youtu.be/hMJAlbJIS7E?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

#include<vector>
#include<string> 
#include<iostream>
using namespace std;

void getStairPath(int n,vector<string> &v,string temp)
{
    if(n<0)
    {
        return;
    }
    else if(n==0)
    {
        v.push_back(temp);
    }
    else
    {
        //taking one step
        getStairPath(n-1,v,temp+"->1");
        //taking two steps
        getStairPath(n-2,v,temp+"->2");
        //taking 3 steps
        getStairPath(n-3,v,temp+"->3");
    }
}

int main()
{
    int n;
    cin>>n;
    vector<string> v;
    getStairPath(n,v,"");

    cout<<"Total number of ways : "<<v.size()<<"\n\n";
    for(auto &ways:v)
    {
        cout<<ways<<"\n";
    }
}