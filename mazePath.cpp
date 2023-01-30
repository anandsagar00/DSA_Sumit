//Question : https://youtu.be/ox3TswFFKDI?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

//Explanation : https://www.pepcoding.com/resources/online-java-foundation/recursion-with-arraylists/get_maze_paths/topic

//Solution : https://youtu.be/7i41gZLXe5k?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

//NOTE : You can only move down and right

#include<vector>
#include<string>
#include<iostream>

using namespace std;

void getMazePaths(int i,int j,int n,int m,vector<string> &v,string temp)
{
    if(i>=n || j>=m )
    {
        return;
    }
    else if(i==n-1 && j==m-1)
    {
        v.push_back(temp);
    }
    else
    {
        //moving down
        getMazePaths(i+1,j,n,m,v,temp+"D");
        //moving right
        getMazePaths(i,j+1,n,m,v,temp+"R");
    }
}

int main()
{
    // NxM matrix , number of ways to get out of NxM matrix by moving only right and down
    // Starting point (0,0) and exit point (N-1,M-1)

    int n,m;
    cin>>n>>m;

    vector<string> v;

    getMazePaths(0,0,n,m,v,"");

    int l=v.size();
    cout<<"Total Possible paths are : "<<l<<"\n";
    for(auto &paths:v)
    {
        cout<<paths<<"\n";
    }
}