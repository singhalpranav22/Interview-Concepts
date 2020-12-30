// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

// Notice that the solution set must not contain duplicate triplets.

 

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Example 2:

// Input: nums = []
// Output: []
// Example 3:

// Input: nums = [0]
// Output: []
 

// Constraints:

// 0 <= nums.length <= 3000
// -105 <= nums[i] <= 105

// Fisrt sort,Fix i, then use two pointer approach to find the rest two numbers (2-Sum Approach) taking care of the duplicates.

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        vector<vector<int> > ans;
        if(v.size()<3) return ans;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-2;i++)
        {
            if(i!=0){
            if(v[i]==v[i-1]) continue;}
            int trgt = (-1)*v[i];
            int j=i+1;
            int k=v.size()-1;
            while(j<k)
            {
                if(j!=i+1){
                if(v[j]==v[j-1])
                {
                    j++;
                    continue;
                }}
                if(k!=v.size()-1)
                {
                    if(v[k]==v[k+1]){
                        k--;
                        continue;
                    }
                }
                int tmp=v[j]+v[k];
                if(tmp==trgt)
                {
                    vector<int> t;
                    t.push_back(v[i]);
                    t.push_back(v[j]);
                    t.push_back(v[k]);
                    ans.push_back(t);
                    j++;
                    k--;
                }
                else if(tmp<trgt)
                {
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return ans;
    }
};
