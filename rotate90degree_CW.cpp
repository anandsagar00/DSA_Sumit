//Question link : https://youtu.be/0qj4kRcuKqo?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk
//Rotate a matrix by 90 degress Clock-Wise
//The Matrix is a square Matrix

#include <iostream>
#include<algorithm>
#include <vector>

using namespace std;

vector<vector<int> > input()
{
    // takes input in a 2d vector and return a 2d vector
    int r;
    cin >> r;

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

void rotate90(vector<vector<int> > &arr)
{
    //The matrix is a sqaure matrix 

    //Rotating 90 degree CW is achieved by first transforming the matrix and then reversing each row of the matrix
    int n=arr.size();

    //First we will transform

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            //we will be doing it only for either lower or upper traingle as if we perform for all element then matrix will
            //remain same only
            if(i>j)
            swap(arr[i][j],arr[j][i]);
        }
    }
    cout<<"\nAfter Transformation the matrix is : \n";
    printMatrix(arr);

    for(int i=0;i<n;i++)
    {
        reverse(arr[i].begin(),arr[i].end());
    }

    cout<<"\nMatrix after rotating 90 degree clockwise is : \n";
    printMatrix(arr);
}

int main()
{
    vector<vector<int> > arr1 = input();

    cout << "Original input : \n";
    printMatrix(arr1);
    rotate90(arr1);
}