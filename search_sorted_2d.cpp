/*
Question : https://youtu.be/N1RyGhXJ7Zc?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

Search in a sorted 2d array , all rows and cols will be sorted

Solution : https://youtu.be/5vP0-g94xEA?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

*/

#include <iostream>
#include<algorithm>
#include <vector>

using namespace std;

vector<vector<int> > input()
{
    // takes input in a 2d vector and return a 2d vector
    int r;
    cin >>r;

    int c=r;

    vector<vector<int> > arr(r, vector<int>(c, 0));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cin >> arr[i][j];
    }
    return arr;
}

void printMatrix(vector<vector<int> > &arr1)
{
    int r1 = arr1.size();
    int c1 = arr1[0].size();

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
            cout << arr1[i][j] << " ";
        cout << "\n";
    }
}

void search(vector<vector<int> > &arr,int key)
{
    int r = arr.size();
    int c = arr[0].size();

    int i=0 , j=c-1;

    int flag=0;//to denote found or not

    while(i<r && j>=0)
    {
        if(key==arr[i][j])
        {
            cout<<i<<"\n"<<j<<"\n";
            flag=1;
            break;
        }
        else if(key>arr[i][j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    if(!flag)
    cout<<"Not Found\n";
}

int main()
{
    vector<vector<int> > arr = input();

    int key;
    cin>>key;

    // cout << "Original input : \n";
    // printMatrix(arr);
    
    search(arr,key);
}