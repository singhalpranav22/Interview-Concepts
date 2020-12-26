// Not of type LCS
// Solution : https://www.youtube.com/watch?v=UflHuQj6MVA&ab_channel=TECHDOSE
// Given a string s, return the longest palindromic substring in s.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)dp[i][i]=1; // single character is palindrome
        int lmx=0,rmx=0;
        // check for size 2 strings
        for(int i=1;i<n;i++)
        {
            if(s[i-1]==s[i]) {
                dp[i-1][i]=1;
                lmx=i-1;rmx=i;
            }
        }
        // for string abcba outer a's are equal and inner (bca) should be palindrome which can be found by dp table
        int mx=0;
        
        int currlen=2; // checking windows of 3 till size of string for palindromes
        while(currlen<n)
        {
            int i=0;
            int j=currlen;
            while(j<n)
            {
                 if(s[i]==s[j] && dp[i+1][j-1]==1)
                    {
                        dp[i][j]=1;
                        if(abs(j-i+1)>mx)
                        {
                            // cout<<i<<" "<<j<<endl;
                            mx=abs(j-i+1);
                            lmx=i;
                            rmx=j;
                        }
                    }
                i++;j++;
            }
            currlen++;
        }
        string ans;
        for(int i=lmx;i<=rmx;i++) ans+=s[i];
        return ans;
        
    }
};