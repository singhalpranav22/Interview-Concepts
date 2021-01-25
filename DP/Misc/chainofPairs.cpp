// Problem Description

// Given a N * 2 array A where (A[i][0], A[i][1]) represents the ith pair.

// In every pair, the first number is always smaller than the second number.

// A pair (c, d) can follow another pair (a, b) if b < c , similarly in this way a chain of pairs can be formed.

// Find the length of the longest chain subsequence which can be formed from a given set of pairs.



// Problem Constraints
// 1 <= N <= 103

// 1 <= A[i][0] < A[i][1] <= 104



// Input Format
// First and only argument is an 2D integer array A of size N * 2 representing the N pairs.



// Output Format
// Return a single integer denoting the length of longest chain subsequence of pairs possible under given constraint.



// Example Input
// Input 1:

//  A = [  [5, 24]
//         [39, 60]
//         [15, 28]
//         [27, 40]
//         [50, 90]
//      ]
// Input 2:

 
// A = [   [10, 20]
//         [1, 2]
//      ]


// Example Output
// Output 1:

//  3
// Output 2:

//  1


// Example Explanation
// Explanation 1:

//  Longest chain that can be formed is of length 3, and the chain is [ [5, 24], [27, 40], [50, 90] ]
// Explanation 2:

//  Longest chain that can be formed is of length 1, and the chain is [ [1, 2] ] or [ [10, 20] ]

// Like longest increasing subsequence
int dp[1004][1004];
int find(vector<vector<int> > &A,int i,int prev,int prevind)
{
    if(i<0) return 0;
    if(dp[i][prevind]!=-1) return dp[i][prevind];
    if(A[i][1]<prev)
      {
          return dp[i][prevind]=max(1+find(A,i-1,A[i][0],i),find(A,i-1,prev,prevind));
      }
     else return dp[i][prevind]=find(A,i-1,prev,prevind);
    
}
int Solution::solve(vector<vector<int> > &A) {
    memset(dp,-1,sizeof(dp));
    if(A.size()==0) return 0;
    return find(A,A.size()-1,10001,A.size());
}
