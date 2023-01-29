//Write a C++ program to multiply 2 matrices , print not possible if both can't be multiplied

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

    cout<<"The resultant matrix is : \n";
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        cout<<arr1[i][j]<<" ";
        cout<<"\n";
    }
}

void multiply(vector<vector<int> > &arr1,vector<vector<int> > &arr2)
{
    //Multiplies two matrices and prints the result on screen 
    //If can't be multiplied then prints , CAN'T BE MULTIPLIED

    int r1=arr1.size();
    int c1=arr1[0].size();

    int r2=arr2.size();
    int c2=arr2[0].size();

    if(c1==r2)
    {
        vector<vector<int> > ans(r1,vector<int>(c2,0));//The answer will of order r1xc2
        
        for(int i=0;i<r1;i++)
        {
            for(int j=0;j<c1;j++)
            {
                int sum=0;
                for(int k=0;k<c1;k++)
                {
                    sum+=(arr1[i][k]*arr2[k][j]);
                }
                ans[i][j]=sum;
            }
        }
        printMatrix(ans);
    }
    else
    {
        cout<<"\nCAN'T BE MULTIPLIED\n";
    }
}

int main()
{
    vector<vector<int> > arr1=input();
    vector<vector<int> > arr2=input();
    multiply(arr1,arr2);
}