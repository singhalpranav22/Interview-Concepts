// Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of given string.


// Example 1:

// Input: str = "ababbbabbababa"
// Output: 3
// Explaination: After 3 partitioning substrings 
// are "a", "babbbab", "b", "ababa".

// Example 2:

// Input: str = "aaabba"
// Output: 1
// Explaination: The substrings after 1
// partitioning are "aa" and "abba".

// Your Task:
// You do not need to read input or print anything, Your task is to complete the function palindromicPartition() which takes the string str as input parameter and returns minimum number of partitions required.

// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
public:
  int dp[505][505];
    bool isPalin(string s,int i,int j)
    {
        int n=s.length();
        for(int k=i,p=j;k<=j,p>=i;k++,p--)
        {
            if(s[k]!=s[p])
                return false;
             
        }
        return true;
    }
    int solve(string s,int i,int j)
    {
        if(i>=j) return 0;
        if(isPalin(s,i,j)) return 0; // If that partition is already a palin than no more partitions are required
        int ans=INT_MAX;
        if(dp[i][j]!=-1)
            return dp[i][j];
        for(int k=i;k<j;k++)
        {
            int fhlf;
            if(dp[i][k]!=-1)
               {
                   fhlf=dp[i][k];
               }
               else
               {
                fhlf=solve(s,i,k);
                dp[i][k]=fhlf;
               }
            int shlf;
            if(dp[k+1][j]!=-1)
             shlf=dp[k+1][j];
             else
             {
             shlf=solve(s,k+1,j);
             dp[k+1][j]=shlf;
             }
            int tmp=fhlf+shlf+1;
            ans=min(ans,tmp);
        }
        return dp[i][j]=ans;
    }
    int palindromicPartition(string s)
    {
        memset(dp,-1,sizeof(dp));
        int n=s.length();
        
        return solve(s,0,n-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends