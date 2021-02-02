// Problem Description

// Given an N x M matrix A of non-negative integers representing the height of each unit cell in a continent, the "Blue lake" touches the left and top edges of the matrix and the "Red lake" touches the right and bottom edges.

// Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

// Find the number of cells from where water can flow to both the Blue and Red lake.



// Problem Constraints
// 1 <= M, N <= 1000

// 1 <= A[i][j] <= 109



// Input Format
// First and only argument is a 2D matrix A.



// Output Format
// Return an integer denoting the number of cells from where water can flow to both the Blue and Red lake.



// Example Input
// Input 1:

//  A = [
//        [1, 2, 2, 3, 5]
//        [3, 2, 3, 4, 4]
//        [2, 4, 5, 3, 1]
//        [6, 7, 1, 4, 5]
//        [5, 1, 1, 2, 4]
//      ]
// Input 2:

//  A = [
//        [2, 2]
//        [2, 2]
//      ]


// Example Output
// Output 1:

//  7
// Output 2:

//  4


// Example Explanation
// Explanation 1:

//  Blue Lake ~   ~   ~   ~   ~ 
//         ~  1   2   2   3  (5) *
//         ~  3   2   3  (4) (4) *
//         ~  2   4  (5)  3   1  *
//         ~ (6) (7)  1   4   5  *
//         ~ (5)  1   1   2   4  *
//            *   *   *   *   * Red Lake
//  Water can flow to both lakes from the cells denoted in parentheses.

// Explanation 2:

//  Water can flow from all cells.

int n,m;
void dfs(int i,int j,vector<vector<int> > &A,vector<vector<int> > &b) // b is the visited array
{
    if(b[i][j]==0) b[i][j]=1;
    if(i>0 && A[i-1][j]>=A[i][j] && b[i-1][j]==0) dfs(i-1,j,A,b);
    if(j>0 && A[i][j-1]>=A[i][j] && b[i][j-1]==0)  dfs(i,j-1,A,b);
    if(j<m-1 && A[i][j+1]>=A[i][j] && b[i][j+1]==0) dfs(i,j+1,A,b);
    if(i<n-1 && A[i+1][j]>=A[i][j] && b[i+1][j]==0) dfs(i+1,j,A,b);
    return;
    
}

int Solution::solve(vector<vector<int> > &A) {
     n=A.size();
     m=A[0].size();
    vector<vector<int> > blue(n,vector<int> (m,0));
    vector<vector<int> > red(n,vector<int> (m,0));
    for(int i=0;i<m;i++) dfs(0,i,A,blue);
    for(int i=1;i<n;i++) dfs(i,0,A,blue);
    for(int i=0;i<n;i++) dfs(i,m-1,A,red);
    for(int i=m-2;i>=0;i--) dfs(n-1,i,A,red);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(blue[i][j]==1 && red[i][j]==1) ans++;
        }
    }
    
    return ans;
}
