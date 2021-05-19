// 647. Palindromic Substrings
// Medium

// 4319

// 138

// Add to List

// Share
// Given a string s, return the number of palindromic substrings in it.

// A string is a palindrome when it reads the same backward as forward.

// A substring is a contiguous sequence of characters within the string.

 

// Example 1:

// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
// Example 2:

// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

// Constraints:

// 1 <= s.length <= 1000
// s consists of lowercase English letters.

class Solution {
public:
    int dp[1003][1003];
    int countSubstrings(string s) {
       // dp[i][j] store whether the string between i and j index is palindrome or not
        int n=s.length();
        memset(dp,0,sizeof(dp));
        int ans=n;
        for(int i=0;i<n;i++) dp[i][i]=1;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]) dp[i][i+1]=1,ans++;
        }
        int gap=2;
       
        while(gap<n){
             int i=0;
            while(i+gap<n){
            if(s[i]==s[i+gap]){
                if(dp[i+1][i+gap-1]==1) ans++,dp[i][i+gap]=1;
            }
                i++;
            }
            gap++;
            
        }
        return ans;
    }
};