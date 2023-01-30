//Question : https://youtu.be/xt0Og8YaON4?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

// Solution : https://youtu.be/6YIWq2JGzEQ?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

/*
The saddle point is defined as the least value in the row and the maximum value in the column.

//Saddle point reference image : https://upload.wikimedia.org/wikipedia/commons/thumb/1/1e/Saddle_point.svg/1200px-Saddle_point.svg.png
*/

// Note : There can only be 1 or 0 saddle point in a matrix , think why 

#include <iostream>
#include<algorithm>
#include <vector>

using namespace std;

vector<vector<int> > input()
{
    // takes input in a 2d vector and return a 2d vector
    int r,c;
    cin >>r>>c;

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

void findSaddlePt(vector<vector<int> > arr)
{
    int r = arr.size();
    int c = arr[0].size();

    int flag=0;//this will denote if saddle point found or not
    //Logic : find the min in the row and check if it is max in that col .

    for(int i=0;i<r;i++)
    {
        int min_col=0;
        int mn=arr[i][0];
        //finding the min in the row
        for(int j=1;j<c;j++)
        {
            if(arr[i][j]<mn)
            {
                mn=arr[i][j];
                min_col=j;
            }
        }
        //finding max in the col
        int mx=arr[0][min_col];
        for(int j=1;j<r;j++)
        {
            mx=max(mx,arr[j][min_col]);
        }
        if(mn==mx)
        {
            cout<<"\nSaddle point is : "<<mx<<"\n";
            flag=1;
            break;
        }
    }

    if(flag==0)
    cout<<"\nNO SADDLE POINT.\n";
}

int main()
{
    vector<vector<int> > arr = input();

    cout << "Original input : \n";
    printMatrix(arr);
    
    findSaddlePt(arr);
}