//Question : https://youtu.be/xt0Og8YaON4?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

// Solution : https://youtu.be/6YIWq2JGzEQ?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

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
    int r1 = arr1.size();
    int c1 = arr1[0].size();
    
}

int main()
{
    vector<vector<int> > arr = input();

    cout << "Original input : \n";
    printMatrix(arr);
    
    findSaddlePt(arr);
}