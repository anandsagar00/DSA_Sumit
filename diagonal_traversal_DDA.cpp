//Question : https://youtu.be/rydBe9U-RtY?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

//Solution : https://youtu.be/lvRdFCMD_Ew?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

//Input is a square matrix .

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

void diagonalTraverse(vector<vector<int> > arr)
{
    int n=arr.size();//since it is a square matrix so r=c

    //Logic : the gap in i and j of a diagonal remains constant

    for(int g=0;g<n;g++)
    {
        for(int i=0,j=g;j<n;i++ ,j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }

}

int main()
{
    vector<vector<int> > arr=input();

    cout<<"Input matrix is : \n";
    printMatrix(arr);

    cout<<"\nDiagonal traversal of Upper Triangle of matrix is : \n";
    diagonalTraverse(arr);
}