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

int Solution::numTrees(int A) {
    vector<int> dp(A+1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=A; i++) 
        for(int j=0; j<i; j++)
            dp[i] += dp[j]*dp[i-j-1];
    return dp[A];
}