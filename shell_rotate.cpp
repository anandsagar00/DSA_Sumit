//Question : https://youtu.be/Eu1XAfmnGZ4?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

//Pre-requisite : Spiral Traversal of a 2d matrix

//The rotation can be CW or ACW 
//if rotations is +ve then CW , negative then ACW

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

void shellRotate(vector<vector<int> > arr,int shell,int k)
{
    //k is a variable which tell us how many times to rotate
    int r=arr.size();
    int c=arr[0].size();

    //reach to the shell , fill the data of the shell in a 1d array , perform rotations on it , and then fill back the elements

    //Spiral traversal is  a pre-req

    //We will require 4 pointers , one to point on each corner of the shell

    //First 4 lines are pointers pointing to 0th shell , we will modify it to point to required shell number [shell]
    int minr=0;
    int maxr=r-1;
    int minc=0;
    int maxc=c-1;

    //adjusting a/c to required shell

    minr+=shell;
    maxr-=shell;
    minc+=shell;
    maxc-=shell;

    vector<int> v;//this array will store the elements of the shell

    //Extracting SHELL from matrix

    //left wall - in left wall only i will increase , j will be fixed to minc
    for(int i=minr,j=minc;i<=maxr;i++)
    v.push_back(arr[i][j]);

    //Bottom wall - here only j will change , i will be fixed to maxr
    for(int i=maxr,j=minc+1;j<=maxc;j++)
    v.push_back(arr[i][j]);

    //Right wall - here only i will change , j will be fixed to maxc
    for(int i=maxr-1,j=maxc;i>=minr;i--)
    v.push_back(arr[i][j]);

    //top wall - here only j will change , i will be fixed to minr
    for(int i=minr,j=maxc-1;j>minc;j--)
    v.push_back(arr[i][j]);

    if(k<0)
    {
        //rotating -2 ACW in an array of length 6 will have rotating 4 CW , doing the same here
        int ck=k;
        k=abs(k);
        k=k%v.size();
        k=v.size()-k;
    }
    else
    {
        k=(k%v.size());
    }

    //rotating the array , k times

    reverse(v.begin(),v.begin()+k);
    reverse(v.begin()+k,v.end());
    reverse(v.begin(),v.end()); // in this stage the array has been rotated


    //Now we will put the elements back in the shell

    int ind=0 , sz=v.size(); // to acces elements of array v

    //left wall - in left wall only i will increase , j will be fixed to minc
    for(int i=minr,j=minc;i<=maxr && ind<sz;i++,ind++)
    arr[i][j]=v[ind];

    //Bottom wall - here only j will change , i will be fixed to maxr
    for(int i=maxr,j=minc+1;j<=maxc && ind<sz;j++,ind++)
    arr[i][j]=v[ind];

    //Right wall - here only i will change , j will be fixed to maxc
    for(int i=maxr-1,j=maxc;i>=minr && ind<sz;i--,ind++)
    arr[i][j]=v[ind];

    //top wall - here only j will change , i will be fixed to minr
    for(int i=minr,j=maxc-1;j>minc && ind<sz;j--,ind++)
    arr[i][j]=v[ind];

    cout<<"\nShell rotated matrix is : \n";
    printMatrix(arr);
}

int main()
{
    vector<vector<int> > arr1 = input();

    //Assuming that shell starts from 0
    int shell;
    cin>>shell;
    int rotations;
    cin>>rotations;

    cout << "Original input : \n";
    printMatrix(arr1);
    
    shellRotate(arr1,shell,rotations);
}