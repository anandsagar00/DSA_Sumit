//Question : https://youtu.be/97mF4juql6g?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk
/*
    0 : NOTHING
    1 : NOTHING
    2 : ABC
    3 : DEF
    4 : GHI
    5 : JKL
    6 : MNO
    7 : PQRS
    8 : TUV
    9 : WXYZ
*/

// You have to take a string of digits as input and print all the possibilities that can be generated on keypad

#include<iostream>
#include<vector>
#include<string>

using namespace std;

//this is an array which basically maps keypad string to index 
string keypad[]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void generate(string &s,int i,vector<string> &v)
{
    if(i>=s.length())
    {
        v.push_back("");
    }
    else
    {
        generate(s,i+1,v);
        
        int l=v.size(); // current length of vector , i.e. how many elements are already there

        //In this loop we will add the current keystrokes combinations , in the already generated one
        for(int k=0;k<l;k++)
        {
            string str=v[k];
            for(auto letters:keypad[s[i]-'0'])
            {
                string nstr=letters+str;//adding the letters in the front
                v.push_back(nstr);
            }
        }
        v.erase(v.begin(),v.begin()+l);
    }
}

int main()
{
    string s;
    cin>>s;

    vector<string> v;

    generate(s,0,v);

    //Sorting the output
    sort(v.begin(),v.end());

    for(auto &strings:v)
    {
        cout<<strings<<"\n";
    }
}