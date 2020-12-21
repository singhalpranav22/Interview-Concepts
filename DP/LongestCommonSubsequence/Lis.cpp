// Longest Increasing Subsequence code
// Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.

// Example 1:

// Input:
// N = 16
// A[]={0,8,4,12,2,10,6,14,1,9,5
//      13,3,11,7,15}
// Output: 6
// Explanation:Longest increasing subsequence
// 0 2 6 9 13 15, which has length 6
#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(int, int[]);

int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];

        //calling method longestSubsequence()
        cout << longestSubsequence(n, a) << endl;
    }
}
// } Driver Code Ends


// return length of longest strictly increasing subsequence
int dp[1003][1003];
int lis(int n,int prev,int a[])
{
    if(n==-1) return 0;
    
    if(dp[n][prev]!=-1) 
      return dp[n][prev];
      
    if(a[n]<a[prev])
    {
        return dp[n][prev]=max(lis(n-1,n,a)+1,lis(n-1,prev,a));
    }
    else 
     return dp[n][prev]=lis(n-1,prev,a);
}
int longestSubsequence(int n, int a[])
{
   // your code here

   memset(dp,-1,sizeof(dp));
   int b[n+1];
   b[n]=10006;
   for(int i=0;i<n;i++) b[i]=a[i];
   return lis(n-1,n,b);
}
