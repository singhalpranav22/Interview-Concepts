// Given an integer A, how many structurally unique BST’s (binary search trees) exist that can store values 1…A?

// Input Format:

// The first and the only argument of input contains the integer, A.
// Output Format:

// Return an integer, representing the answer asked in problem statement.
// Constraints:

// 1 <= A <= 18
// Example:

// Input 1:
//     A = 3

// Output 1:
//     5

// Explanation 1:

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3
Lets say you know the answer for values i which ranges from 0 <= i <= n - 1.
How do you calculate the answer for n.

Lets consider the number [1, n]
We have n options of choosing the root.
If we choose the number j as the root, j - 1 numbers fall in the left subtree, n - j numbers fall in the right subtree. We already know how many ways there are to forming j - 1 trees using j - 1 numbers and n -j numbers.
So we add number(j - 1) * number(n - j) to our solution.


int dp[101];
int solve(int n)
{
    if(n==0 || n==1) return 1;
    if(dp[n]!=-1) return dp[n];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=solve(i-1)*solve(n-i);
    }
    return dp[n]=ans;
}
int Solution::numTrees(int A) {
    memset(dp,-1,sizeof(dp));
    return solve(A);
    
}