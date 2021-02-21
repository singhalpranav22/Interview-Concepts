// Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*' where: 

// '.' Matches any single character.​​​​
// '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).

 

// Example 1:

// Input: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
// Example 2:

// Input: s = "aa", p = "a*"
// Output: true
// Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
// Example 3:

// Input: s = "ab", p = ".*"
// Output: true
// Explanation: ".*" means "zero or more (*) of any character (.)".
// Example 4:

// Input: s = "aab", p = "c*a*b"
// Output: true
// Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
// Example 5:

// Input: s = "mississippi", p = "mis*is*p*."
// Output: false
 

// Constraints:

// 0 <= s.length <= 20
// 0 <= p.length <= 30
// s contains only lowercase English letters.
// p contains only lowercase English letters, '.', and '*'.
// It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
 // This is recursive coding only, can be converted to dp
class Solution {
public:
    vector<vector<int> > dp;
    int solve(int i,int j,int n,int m,string &A,string &B)
{
     if(i>=n && j>=m) return true;
        if(j>=m) return false;
     if(i>=n)
     {
         if(B[j]=='*')
              dp[i][j]=solve(i,j+1,n,m,A,B);
         else
             return dp[i][j]=false;
     }
        if(dp[i][j]!=-1) return dp[i][j];
    if((A[i]==B[j]) || B[j]=='?') {
    
        return dp[i][j]=solve(i+1,j+1,n,m,A,B);
    }
    
    if(B[j]=='*')
    {
        return dp[i][j]=solve(i+1,j,n,m,A,B) || solve(i,j+1,n,m,A,B);
    }
    
    return dp[i][j]=false;
}
    bool isMatch(string A, string B) {
        int n=A.length();
        string temp;
        int i=0;
        char prev='~';
        while(i<B.length())
        {
            if(B[i]=='*' && prev=='*')
            {
                 i++;
                 continue;
            }
            else
            {
                prev=B[i];
                temp+=B[i];
                i++;
            }
        }
        B=temp;
        int m=B.length();
     dp.resize(n+2,vector<int> (m+2,-1));
    return solve(0,0,n,m,A,B);
    }
};