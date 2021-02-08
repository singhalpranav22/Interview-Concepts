// Input Format
// First and only argument is an 2D integer array A of size N * N.



// Output Format
// Return a single integer denoting the maximum path sum from top to bottom in the triangle.



// Example Input
// Input 1:

//  A = [
//         [3, 0, 0, 0]
//         [7, 4, 0, 0]
//         [2, 4, 6, 0]
//         [8, 5, 9, 3]
//      ]
// Input 2:

//  A = [
//         [8, 0, 0, 0]
//         [4, 4, 0, 0]
//         [2, 2, 6, 0]
//         [1, 1, 1, 1]
//      ]


// Example Output
// Output 1:

//  23
// Output 2:

//  19


// Example Explanation
// Explanation 1:

//  Given triangle looks like:  3
//                              7 4
//                              2 4 6
//                              8 5 9 3
//         So max path is (3 + 7 + 4 + 9) = 23
// Explanation 1:

//  Given triangle looks like:  8
//                              4 4
//                              2 2 6
//                              1 1 1 1
//         So max path is (8 + 4 + 6 + 1) = 19

    int dp[1005][1005];
int find(vector<vector<int> > &A,int i,int j,int n)
{
    if(i>=n || j>=n) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j]=A[i][j]+max(find(A,i+1,j,n),find(A,i+1,j+1,n));
}
int Solution::solve(vector<vector<int> > &A) {
    memset(dp,-1,sizeof(dp));
    int n=A.size();
    return find(A,0,0,n);
}
