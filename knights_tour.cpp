// Question : https://youtu.be/EgoKDqfpbMg?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

//Explanation : https://www.pepcoding.com/resources/online-java-foundation/recursion-backtracking/knights_tour/topic

//Solution : https://youtu.be/SP880DBRJ_8?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

//Note : Knight matlab HORSE/GHORA in chess

// Can KNIGHT travel to all cells in the chess of order NxN , if yes then print the moves

#include<iostream>
#include<vector>

using namespace std;

//These are the 8 moves of a KNIGHT
int moves[][2]={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};

void place(int **arr,int i,int j,int count,int n)
{
    if(i<0 || j<0 || i>=n || j>=n || arr[i][j]!=0)
    return;
    else
    {
        //The knight can move in 8 directions
        count++;

        if(count==n*n)
        {
            arr[i][j]=count;
            for(int k=0;k<n;k++)
            {
                for(int l=0;l<n;l++)
                cout<<arr[k][l]<<" ";
                cout<<"\n";
            }
            cout<<"\n";
            arr[i][j]=0;
            return;
        }

        //now move in 8 directions
        for(int k=0;k<8;k++)
        {
            arr[i][j]=count;
            place(arr,i+moves[k][0],j+moves[k][1],count,n);
            arr[i][j]=0;
        }
        arr[i][j]=0;
    }
}

int main()
{
    int n;
    cin>>n;

    int **arr=new int*[n];

    for(int i=0;i<n;i++)
    arr[i]=new int[n];

    int si,sj; //starting i and j where the KNIGHT is standing right now

    cin>>si>>sj;

    place(arr,si,sj,0,n);
}