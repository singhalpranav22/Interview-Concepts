// Given two sequences A, B, count number of unique ways in sequence A, to form a subsequence that is identical to the sequence B.

// Subsequence : A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, “ACE” is a subsequence of “ABCDE” while “AEC” is not).

// Input Format:

// The first argument of input contains a string, A.
// The second argument of input contains a string, B.
// Output Format:

// Return an integer representing the answer as described in the problem statement.
// Constraints:

// 1 <= length(A), length(B) <= 700
// Example :

// Input 1:
//     A = "abc"
//     B = "abc"
    
// Output 1:
//     1

// Explanation 1:
//     Both the strings are equal.

// Input 2:
//     A = "rabbbit" 
//     B = "rabbit"

// Output 2:
//     3

// Explanation 2:
//     These are the possible removals of characters:
//         => A = "ra_bbit" 
//         => A = "rab_bit" 
//         => A = "rabb_it"
        
//     Note: "_" marks the removed character.

int dp[1001][1001];
int solve(string a,string b,int i,int j) // i,j are pointers to A and B
{
    if(j<=0) {  // if the string b is finished than we have got a subsequence
        return dp[i][j]=1;
    }
    if(i<=0) // if the string a is finished and we haven't got a subsequence
    {
        return dp[i][j]=0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    dp[i][j]=0;    // ans for the current pointers
    if(a[i-1]==b[j-1])
    {
        dp[i][j]+=solve(a,b,i-1,j-1);   // decrease pointers of both A and B then find the answer
    }
    dp[i][j]+=solve(a,b,i-1,j);  // decrease pointer of only A and find the answer for getting multiple answers
    return dp[i][j];
}
int Solution::numDistinct(string A, string B) {
    memset(dp,-1,sizeof(dp));
    int n=A.length(),m=B.length();
    
    return solve(A,B,n,m);
    
}
