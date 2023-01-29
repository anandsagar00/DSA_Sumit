//Write a C++ program to Traverse a matrix in wave way

//Question : https://youtu.be/nUUc9DKTBdY?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

#include<iostream>
#include<vector>

using namespace std;

vector<vector<int> > input()
{
    //takes input in a 2d vector and return a 2d vector
    int r,c;
    cin>>r>>c;

    vector<vector<int> > arr(r,vector<int>(c,0));

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        cin>>arr[i][j];
    }
    return arr;
}

void printMatrix(vector<vector<int> > &arr1)
{
    int r1=arr1.size();
    int c1=arr1[0].size();

    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        cout<<arr1[i][j]<<" ";
        cout<<"\n";
    }
}

void wave_traverse(vector<vector<int> > arr)
{
    int r=arr.size();
    int c=arr[0].size();

    cout<<"\nWave traversal is : \n";

    for(int i=0;i<c;i++)
    {
        if(i%2==0)
        {
            for(int j=0;j<r;j++)
            cout<<arr[j][i]<<" ";
        }
        else
        {
            for(int j=r-1;j>=0;j--)
            cout<<arr[j][i]<<" ";
        }
    }
    cout<<"\n";
}

int main()
{
    vector<vector<int> > arr1=input();

    cout<<"Original input : \n";
    printMatrix(arr1);

    wave_traverse(arr1);
}