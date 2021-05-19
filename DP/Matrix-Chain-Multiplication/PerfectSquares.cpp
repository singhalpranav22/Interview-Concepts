// 279. Perfect Squares
// Medium

// 4412

// 238

// Add to List

// Share
// Given an integer n, return the least number of perfect square numbers that sum to n.

// A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

 

// Example 1:

// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.
// Example 2:

// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.
 

// Constraints:

// 1 <= n <= 104

class Solution {
public:
    int res = INT_MAX;
    int dp[10006];        
    int find(int sum){
        if(sum==0) return 0;
        if(dp[sum]!=-1) return dp[sum];
        int ans=INT_MAX-5;
        for(int i=1;i*i<=sum;i++){ 
            int tp=INT_MAX;
            if(sum-(i*i)>=0) tp=find(sum-(i*i))+1;
            ans=min(tp,ans);
        }
        return dp[sum]=ans;
    }
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        return find(n);
    }
};