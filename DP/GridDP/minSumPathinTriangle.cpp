// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

// For example, given the following triangle

// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

//  Note:
// Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle. 

int dp[1005][1005];
int find(vector<vector<int> >&A,int r,int j,int n)
{
    if(r==n) return 0;
    int mn=INT_MAX;
    if(dp[r][j]!=-1) return dp[r][j];
    
        int x;
        if(dp[r+1][j]!=-1)
        x=dp[r+1][j];
        else
        x=find(A,r+1,j,n);
        int y;
        if(dp[r+1][j+1]!=-1)
        y=dp[r+1][j+1];
        else
        y=find(A,r+1,j+1,n);
        mn=min(mn,min(x,y));
    
    return dp[r][j]=mn+A[r][j];
}

int Solution::minimumTotal(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    memset(dp,-1,sizeof(dp));
    int r=A.size();
    return find(A,0,0,r);
    
    
}
