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

void placeQueens(int **arr,int i,int j,int n,vector<vector<int> > &ans,vector<int> temp)
{
    if(i==n)
    {
        //we have placed all queens succesfully
        if(!temp.empty())
        ans.push_back(temp);
        return;
    }
    else if(i<0 || j<0 || i>=n || j>=n)
    return ;
    else
    {
        if(isSafe(arr,i,j,n))
        {
            arr[i][j]=1;
            temp.push_back(i);
            temp.push_back(j);
            placeQueens(arr,i+1,0,n,ans,temp);
            temp.pop_back();
            temp.pop_back();
            arr[i][j]=0;
        }
        placeQueens(arr,i,j+1,n,ans,temp);
    }
}

int main()
{
    int n;
    cin>>n;
    int **arr=new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
    }

    vector<vector<int> > ans;
    vector<int> temp;
    placeQueens(arr,0,0,n,ans,temp);

    for(auto &v:ans)
    {
        int l=v.size();
        int i=0;
        while(i<l)
        {
            cout<<v[i]<<"-"<<v[i+1]<<", ";
            i+=2;
        }
        cout<<".\n";
    }
}