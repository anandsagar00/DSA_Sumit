/*
Problem : https://www.pepcoding.com/resources/online-java-foundation/stacks-and-queues/sliding_window_maximum/topic

You are given an array arr of n numbers. You are also given a number k, representing the size of the window.
You are required to find and print the maximum element in every window of size k.
First Sliding window is a subarray of size k, starting from 0th index ending at index k-1, i.e. subarray [0, k-1].
First Sliding window is a subarray of size k, starting from 0th index ending at index k-1, i.e. subarray [0, k-1].
On each "slide", this window moves right by one position, i.e. the new window is now a subarray of size k having indices [1, k], and so on.
Example:
Consider an array = {7, 5, 2, 6, 4, 3, 8, 1, 5} and window size k = 4. Then the maximum of each window will be:
Ans = [7, 6, 6, 8, 8, 8].
*/

//Solution : https://youtu.be/tCVOQX3lWeI?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

#include<iostream>
#include<fstream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<utility>
#include<unordered_map>
#include<set>
#include<map>
#include<unordered_set>
#include<string>
#include<limits.h>
using namespace std;
#define ll long long int
const int mod=1e9+7;

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n,0);

    for(int i=0;i<n;i++)
    cin>>arr[i];
    
    //TODO : Complete further

}