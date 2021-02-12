// Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Determine if you are able to reach the last index.

 

// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:

// Input: nums = [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

// Constraints:

// 1 <= nums.length <= 3 * 104
// 0 <= nums[i] <= 105

class Solution {
public:
    bool dp[100007];
int vis[100007];
    bool solve(int i,int n,vector<int> &A)
{
    if(i==n) return true;
    if(i>n) return false;
        if(vis[i]==1) return dp[i];
    bool ans=false;
    for(int k=A[i];k>=1;k--)
    {
        ans=solve(i+k,n,A);
        if(ans==true)
        {
            vis[i]=1;
            return dp[i]=true;
        }
    }
        vis[i]=1;
    return dp[i]=false;
    
}
    bool canJump(vector<int>& A) {
        memset(vis,-1,sizeof(dp));
    memset(dp,false,sizeof(dp));
    return solve(0,A.size()-1,A);
    }
};