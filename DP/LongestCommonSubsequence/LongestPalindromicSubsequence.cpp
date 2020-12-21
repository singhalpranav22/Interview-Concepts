// Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

// Example 1:
// Input:

// "bbbab"
// Output:
// 4
// One possible longest palindromic subsequence is "bbbb".
 

// Example 2:
// Input:

// "cbbd"
// Output:
// 2
// One possible longest palindromic subsequence is "bb".
 
Rhea Ma'am OP
Big Fan
// Constraints:

// 1 <= s.length <= 1000
// s consists only of lowercase English letters.

#include<bit/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        // question boils down to find the LCS between the string and it's reverse
        string r;
        
        int dp[1002][1002];
        memset(dp,0,sizeof(dp));
        int n=s.length();
        for(int i=n-1;i>=0;i--)r+=s[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==r[j-1])
                     dp[i][j]=dp[i-1][j-1]+1;
                 else
                 {
                     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                 }
            }
        }
        return dp[n][n];
        
    }
};