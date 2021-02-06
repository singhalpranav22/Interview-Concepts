// Given A, B, C, find whether C is formed by the interleaving of A and B.

// Input Format:*

// The first argument of input contains a string, A.
// The second argument of input contains a string, B.
// The third argument of input contains a string, C.
// Output Format:

// Return an integer, 0 or 1:
//     => 0 : False
//     => 1 : True
// Constraints:

// 1 <= length(A), length(B), length(C) <= 150
// Examples:

// Input 1:
//     A = "aabcc"
//     B = "dbbca"
//     C = "aadbbcbcac"

// Output 1:
//     1
    
// Explanation 1:
//     "aa" (from A) + "dbbc" (from B) + "bc" (from A) + "a" (from B) + "c" (from A)

// Input 2:
//     A = "aabcc"
//     B = "dbbca"
//     C = "aadbbbaccc"

// Output 2:
//     0

// Explanation 2:
//     It is not possible to get C by interleaving A and B.

// Find LCS of A,C & B,C and than find whether the lcs are equal to A and B respectively and the sum of their lengths is equal to the length of string C
int dp[1005][1005];

string findLCS(string A,string B)
{
    memset(dp,0,sizeof(dp));
    int n=A.length();
    int m=B.length();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(A[i-1]==B[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i=n,j=m;
    string ans="";
    while(i>0 && j>0)
    {
        if(A[i-1]==B[j-1])  
        {
            ans+=A[i-1];
            i--,j--;
        }
        else if(dp[i-1][j]>=dp[i][j-1])
        {
            
            i--;
        }
        else{
            
            j--;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
    
}
int Solution::isInterleave(string A, string B, string C) {
    if(A.length() + B.length() != C.length()) return 0;
    string s1 = findLCS(A,C);
    string s2 = findLCS(B,C);
    if(s1==A && s2==B) return 1;
    else return 0;
    
}
