// Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences.  If multiple answers exist, you may return any of them.

// (A string S is a subsequence of string T if deleting some number of characters from T (possibly 0, and the characters are chosen anywhere from T) results in the string S.)

 

// Example 1:

// Input: str1 = "abac", str2 = "cab"
// Output: "cabac"
// Explanation: 
// str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
// str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
// The answer provided is the shortest such string that satisfies these properties.
 

// Note:

// 1 <= str1.length, str2.length <= 1000
// str1 and str2 consist of lowercase English letters.

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m=str1.length();
        int n=str2.length();
        int dp[m+2][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=m;i++)  // Finding LCS 
        {
            for(int j=1;j<=n;j++){
            if(str1[i-1]==str2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int i=m,j=n;
        string ans;
        int sz=dp[m][n];
        vector<int> v1(sz+2);
        v1[0]=-1;
        v1[sz+1]=m;
        vector<int> v2(sz+2);
        v2[0]=-1;
        v2[sz+1]=n;
        int it=sz;
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                v1[it]=i-1;
                v2[it]=j-1;
                it--;
                i--;
                j--;
            }
            else
            {
              
                if(dp[i-1][j]>=dp[i][j-1])
                {
                    i--;
                }
                else
                    j--;
                
            }
            
                 
        }
        for(int i=sz;i>=0;i--)
        {
            for(int j=v1[i+1]-1;j>v1[i];j--)
                 ans+=str1[j];
            for(int j=v2[i+1]-1;j>v2[i];j--)
                 ans+=str2[j];
            if(i!=0)
                 ans+=str1[v1[i]];
            
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};