class Solution {
public:
    int dp[2506];
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        dp[0]=1;
        for(int i=1;i<n;i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                dp[i]=max(dp[i],dp[j]+1);
                ans=max(ans,dp[i]);
                }
            }
        }
        return ans;
        
        
    }
};

