//Write a C++ program to Traverse a matrix in spiral way

//Question : https://youtu.be/UPEZBPh1UcU?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

//The solution below is one of the best and easiest explanation of all

//Solution : https://youtu.be/SVFXEqn3Ceo 

//Explanation : https://www.pepcoding.com/resources/online-java-foundation/2d-arrays/spiral_display/topic

//Note : Box wala method , keep on printing elements box wise (refere sol video for context)
//       this is also a 4 pointer method

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

void spiral_traverse(vector<vector<int> > arr)
{
    int r=arr.size();
    int c=arr[0].size();


    //these 4 var below will be used to define box
    int minr=0,minc=0,maxr=r-1,maxc=c-1; //initialising min-row , min-col , max-row , max-col pointer

    int total_elements=r*c;
    int count=0;

    cout<<"\nSpiral traversal is : \n";

    while(count<total_elements)//till the number of printed values are less than total elements
    {
        //printing left wall 

        for(int i=minr;i<=maxr;i++)
        {
            //in left wall the rows are changing the col remains fixed as min col
            cout<<arr[i][minc]<<" ";
            count++;
        }

        //bottom wall

        for(int i=minc+1;i<=maxc;i++)
        {
            //in bottom wall the cols are changing where as row remains fixed as maxr
            cout<<arr[maxr][i]<<" ";
            count++;
        }

        //right wall

        for(int i=maxr-1;i>=minr;i--)
        {
            //in right wall the rows are changing where as cols remains fixed as maxc
            cout<<arr[i][maxc]<<" ";
            count++;
        }

        //top wall
        for(int i=maxc-1;i>minc;i--)
        {
            //in top wall the row remains fixed as minr where as cols change
            cout<<arr[minr][i]<<" ";
            count++;
        }

        minr++;
        maxr--;
        minc++;
        maxc--;

    }

    
    cout<<"\n";
}

int main()
{
    vector<vector<int> > arr1=input();

    cout<<"Original input : \n";
    printMatrix(arr1);

    spiral_traverse(arr1);
}