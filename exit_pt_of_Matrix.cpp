// Explanation : https://www.pepcoding.com/resources/online-java-foundation/2d-arrays/exit_point_of_a_matrix/topic

// Question : https://youtu.be/FnywCfCcMRk?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

// Solution : https://youtu.be/FUBlb360kqU?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

/*
Input matrix is a binary matrix (only 0 and 1) , on 1 turn right .... more explanation on link above

Default direction is East
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > input()
{
    // takes input in a 2d vector and return a 2d vector
    int r, c;
    cin >> r >> c;

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

void findExit(vector<vector<int> > arr)
{
    int r = arr.size();
    int c = arr[0].size();

    // this dir variable is a flag which changes on encountering 1
    int dir = 0; // 0 ->  East , 1->South , 2->west , 3->North

    // this is the starting point of the matrix from where the person is going to enter into maze
    int i = 0;
    int j = 0;

    while (i >= 0 && j >= 0 && i < r && j < c)
    {
        if (dir == 0)
        {
            // moving east i.e. increase j keep i constant
            if (arr[i][j] == 0)
            {
                j++;
            }
            else
            {
                // change direction and move him to next place
                dir = 1;
                // to go to south increase row by 1
                i++;
            }
        }
        else if (dir == 1)
        {
            // moving south i.e. increase i keep j constant
            if (arr[i][j] == 0)
            {
                i++;
            }
            else
            {
                // change direction and move him to next place
                dir = 2;
                // to go to west decrease col by 1
                j--;
            }
        }
        else if (dir == 2)
        {
            // moving west i.e. decrease j by 1 keep i constant
            if (arr[i][j] == 0)
            {
                j--;
            }
            else
            {
                // change direction and move him to next place
                dir = 3;
                // to go to north decrease row by 1
                i--;
            }
        }
        else
        {
            // moving up i.e. decrease i by 1 keep j constant
            if (arr[i][j] == 0)
            {
                i--;
            }
            else
            {
                // change direction and move him to next place
                dir = 0;
                // to go to east increase col by 1
                j++;
            }
        }
    }
    
    if(dir==0)
    {
        //while moving east exited
        cout << "Exited on ( " << i << " , " << j-1 << " )  while moving right/east\n";
    }
    else if(dir==1)
    {
        //while moving down/south exited
        cout << "Exited on ( " << i-1 << " , " << j << " )  while moving south/down\n";
    }
    else if(dir==2)
    {
        //while moving left/west exited
        cout << "Exited on ( " << i << " , " << j+1 << " )  while moving left/west\n";
    }
    else
    {
        //while moving up/north exited
        cout << "Exited on ( " << i+1 << " , " << j << " ) while moving north/up\n";
    }
}

int main()
{
    vector<vector<int> > arr1 = input();

    cout << "Original input : \n";
    printMatrix(arr1);

    findExit(arr1);
}