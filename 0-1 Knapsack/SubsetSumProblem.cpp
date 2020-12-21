// We would use knapsack with top-down approach here:
//Problem Description
// https://www.interviewbit.com/problems/subset-sum-problem/#
// Given an integer array A of size N.

// You are also given an integer B, you need to find whether their exist a subset in A whose sum equal B.

// If there exist a subset then return 1 else return 0.
// Filling matrix on the basis to include an element in subset or not
//Table Structure:
// rows=n+1, column=sum+1
// Base Case:
// T F F F F F F F F F
// T 
// T 
// T 
// T 

// recursion relation:
// return f(v,sum-v[n],n-1) || f(v,sum.n-1); Choose or dont choose
bool dp[104][100009];
int solve(vector<int> &A, int B) {
    int n=A.size();
  
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=B;j++)
        {
            if(j==0)
                dp[i][j]=true;
            if(i==0 && j!=0)
             dp[i][j]=false;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=B;j++)
        {
            if(A[i-1]>j)
              dp[i][j]=dp[i-1][j];
             else
             {
                 dp[i][j]=(dp[i-1][j-A[i-1]])||(dp[i-1][j]);
             }
        }
    }
    if(dp[n][B]) return 1;
    else return 0;
}
