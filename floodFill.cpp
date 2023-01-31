//Question : https://youtu.be/FkkgY7qQF_s?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

//Explanation : https://www.pepcoding.com/resources/online-java-foundation/recursion-backtracking/flood_fill/topic

//Solution : https://youtu.be/R1URUB6_y2k?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

// the grid contains 0 and 1 , 1 is obstacle and 0 is free space

//NOTE : I use double pointer concept to assign a Double Dimensional Array , It is a good concept , also
//       it helps in passing a 2d array to a function

// We can move in 3 directions : top (t) , left (l) , down (d) , right (r)


#include<iostream>
#include<vector>
#include<string>
using namespace std;

void getPaths(int **arr,int i,int j,int n,int m,vector<string> &v,string temp)
{
    //first we will check that we are inside the grid and we are not on obstacle

    if(i<0 || j<0 || i>=n || j>=m || arr[i][j]==1)
    return;
    
    else if(i==n-1 && j==m-1)
    {
        v.push_back(temp);
        return;
    }
    else
    {
        //first we will mark that We are visiting this cell , so that it is not visited again in further calls
        arr[i][j]=1;

        //NOW move in 4 directions tldr
        getPaths(arr,i-1,j,n,m,v,temp+"t");//top
        getPaths(arr,i,j-1,n,m,v,temp+"l");//left
        getPaths(arr,i+1,j,n,m,v,temp+"d");//down
        getPaths(arr,i,j+1,n,m,v,temp+"r");//right

        //After calls in all 4 directions complete , we will mark that point back to 0
        arr[i][j]=0;

    }

}

int main()
{
    int n,m;
    cin>>n>>m;

    int **arr=new int*[n];
    
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[m];
    }

    //Now we will be taking input in array

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>arr[i][j];
    }

    vector<string> v;
    getPaths(arr,0,0,n,m,v,"");

    for(auto &paths:v)
    cout<<paths<<"\n";
}