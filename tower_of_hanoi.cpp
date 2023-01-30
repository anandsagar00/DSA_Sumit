// Question : https://youtu.be/uwrc4H3yaJ4?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

//Solution : https://youtu.be/QDBrZFROuA0?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

/*
You are required to enter the number of discs
You have to print instructions, in format n[n1 -> n2] which represents "move nth disc from tower n1 to tower n2".
Following these instructions, all discs should get transferred from source tower to destination tower,
such that no larger disc is placed over a smaller disc.

Rules of game :

You can move only 1 disc at a time.
A larger disc can never be placed under a smaller disc.
You can move only the top-most disc.
*/

//Move All discs from tower A to tower B

#include<iostream>
using namespace std;

void towerOfHanoi(int n,char A,char B,char C,int &count)
{
    //Believe in faith
    if(n==1)
    {
        //For 1 disc directly from A to B
        count++;
        cout<<"Move No. "<<count<<" : Move Disc "<<n<<" From "<<A<<" -> "<<B<<"\n";
    }
    else
    {
        //this will print instr to move n-1 discs from tower A to tower C via tower B
        towerOfHanoi(n-1,A,C,B,count);//believe that n-1 has been arranged already

        count++;
        //only one left in tower A so move it directly to tower B
        cout<<"Move No. "<<count<<" : Move Disc "<<n<<" From "<<A<<" -> "<<B<<"\n";
        
        //Now we will move n-1 discs from tower C to tower B via tower A
        towerOfHanoi(n-1,C,B,A,count);

    }
}

int main()
{
    int n;
    cin>>n;
    int count=0;
    towerOfHanoi(n,'A','B','C',count);
}