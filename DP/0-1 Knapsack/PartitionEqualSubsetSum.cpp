// Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
// Variation of 0-1 Knapsack
// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
// Code :
class Solution {
public:
    int dp[202][20005];
    bool t[202][20005];
    int sum;
    bool f(vector<int> &v,int n,int curr)
    {
        if(n==-1|| curr < (sum/2))
        {
             
             return false;
        }
        if(dp[n][curr]==1)
        {
            return t[n][curr];
        }
        else if(curr==sum/2)
        {
            dp[n][curr]=1;
            return t[n][curr]=true;
        }
        else
        {  
            dp[n][curr]=1;
            return t[n][curr]=f(v,n-1,curr-v[n])||f(v,n-1,curr);
        }
            
    }
    bool canPartition(vector<int>& nums) {
        memset(dp,0,sizeof(dp));
        sum=0;
        for(auto x : nums) sum+=x;
        if(sum&1)
             return false;
        else
            return f(nums,nums.size()-1,sum);
        
        
    }
};

// Write your driver function here..