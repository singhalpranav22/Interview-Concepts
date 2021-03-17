// You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

// If you burst the ith balloon, you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

// Return the maximum coins you can collect by bursting the balloons wisely.

 
// Explanation
// Example 1:

// Input: nums = [3,1,5,8]
// Output: 167
// Explanation:
// nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
// coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
// Example 2:

// Input: nums = [1,5]
// Output: 10
 

// Constraints:

// n == nums.length
// 1 <= n <= 500
// 0 <= nums[i] <= 100

class Solution {
public:
    int dp[505][505];
    int solve(vector<int>&v,int i,int j)
    {
        if(i>=j) return 0;
        int ans=INT_MIN;
        for(int k=i;k<j;k++)
        {
            int fprt,scprt;
            if(dp[i][k]!=-1)
                fprt=dp[i][k];
            else
            {
                fprt=solve(v,i,k);
                dp[i][k]=fprt;
            }
            if(dp[k+1][j]!=-1)
                scprt=dp[k+1][j];
            else{
                scprt=solve(v,k+1,j);
                dp[k+1][j]=scprt;
            }
            int temp=fprt+scprt+v[i-1]*v[k]*v[j];
            if(temp>ans)
                ans=temp;
        }
        return ans;
        
    }
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int sz=nums.size();
        vector <int> v(sz+2);
        v[0]=1;v[sz+1]=1;
        for(int i=0;i<sz;i++)
            v[i+1]=nums[i];
        
         return solve(v,1,sz+1);
        
        
    }
};