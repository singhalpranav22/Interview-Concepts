// Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

// You have the following 3 operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character


// Input Format:

// The first argument of input contains a string, A.
// The second argument of input contains a string, B.
// Output Format:

// Return an integer, representing the minimum number of steps required.
// Constraints:

// 1 <= length(A), length(B) <= 450
// Examples:

// Input 1:
//     A = "abad"
//     B = "abac"

// Output 1:
//     1

// Explanation 1:
//     Operation 1: Replace d with c.

// Input 2:
//     A = "Anshuman"
//     B = "Antihuman"

// Output 2:
//     2

// Explanation 2:
//     => Operation 1: Replace s with t.
//     => Operation 2: Insert i.
int dp[1001][1001];
int f(string a,string b,int i,int j)
{
    if(i<0 && j<0) return 0;
    if(i<0) return j+1;
    if(j<0) return i+1;
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i]==b[j])
    {
        return dp[i][j]=f(a,b,i-1,j-1);
    }
    else
    {
        return dp[i][j]=min(f(a,b,i,j-1)+1,min(f(a,b,i-1,j)+1,f(a,b,i-1,j-1)+1));
    }
}

int Solution::minDistance(string a, string b) {
    memset(dp,-1,sizeof(dp));
    int n=a.length(),m=b.length();
    return f(a,b,n-1,m-1);
    
}
