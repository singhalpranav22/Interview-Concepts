class Solution {
public:
   
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int dp[n];
        dp[0]=nums[0];
        for(int i=1;i<n;i++) dp[i]=INT_MAX;
        int up;
        int ans=0;
        for(int i=1;i<n;i++){
            up = upper_bound(dp,dp+n+1,nums[i])-dp;
            if(up==0?true:dp[up-1]!=nums[i]) {dp[up]=nums[i];
                           ans= max(ans,up);
                                           }
        }
        return ans+1;
    }
};