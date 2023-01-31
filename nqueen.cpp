// Question : https://youtu.be/prZJ0hA43NU?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

//Explanation : https://www.pepcoding.com/resources/online-java-foundation/recursion-backtracking/n_queens/topic

//Solution : https://youtu.be/05y82cP3bJo?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

#include<string>
#include<vector>
#include<iostream>

using namespace std;

//Function to determine , the queen which we are placing right now on the cell is safe or not

bool isSafeLeft(int **arr,int i,int j,int n)
{
    while(j>=0)
    {
        if(arr[i][j]==1)
        return false;
        j--;
    }
    return true;
}

bool isSafeUp(int **arr,int i,int j,int n)
{
     while(i>=0)
    {
        if(arr[i][j]==1)
        return false;
        i--;
    }
    return true;
}

bool isSafeLeftDiagonal(int **arr,int i,int j,int n)
{
     while(i>=0 && j>=0)
    {
        if(arr[i][j]==1)
        return false;
        i--;
        j--;
    }
    return true;
}

bool isSafeRightDiagonal(int **arr,int i,int j,int n)
{
     while(i>=0 && j<n)
    {
        if(arr[i][j]==1)
        return false;
        i--;
        j++;
    }
    return true;
}


bool isSafe(int **arr,int i,int j,int n)
{
    bool left=isSafeLeft(arr,i,j,n);
    bool up=isSafeUp(arr,i,j,n);
    bool ld=isSafeLeftDiagonal(arr,i,j,n);
    bool rd=isSafeRightDiagonal(arr,i,j,n);
    return left && up && ld && rd;
}



int main()
{
    int n;
    cin>>n;

    int **arr=new int*[n];

    for(int i=0;i<n;i++)
    arr[i]=new int[n];

    //TODO : 
}