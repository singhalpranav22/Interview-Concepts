// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

 

// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
// Example 2:

// Input: coins = [2], amount = 3
// Output: -1
// Example 3:

// Input: coins = [1], amount = 0
// Output: 0
// Example 4:

// Input: coins = [1], amount = 1
// Output: 1
// Example 5:

// Input: coins = [1], amount = 2
// Output: 2
 

// Constraints:

// 1 <= coins.length <= 12
// 1 <= coins[i] <= 231 - 1
// 0 <= amount <= 104

class Solution {
    #define ll long long
public:
    bool f=false;
    int dp[10005];
    ll find(vector<int> v,int n,ll sum){
        if(sum==0) {f=true;return 0;}
        if(dp[sum]!=-1) return dp[sum];
        int res=INT_MAX;
        for(int i=0;i<n;i++){
            int ans=INT_MAX;
            if(sum-v[i]>=0)
                ans = find(v,n,sum-v[i]);
            if(ans!=INT_MAX)
                res=min(res,ans+1);
        }
        return dp[sum]=res;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        f=false;
        int ans= find(coins,coins.size(),amount);
        if(f)
            return ans;
        else 
            return -1;
    }
};