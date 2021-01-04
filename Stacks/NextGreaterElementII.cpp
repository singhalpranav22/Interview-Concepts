// Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

// Example 1:
// Input: [1,2,1]
// Output: [2,-1,2]
// Explanation: The first 1's next greater number is 2; 
// The number 2 can't find next greater number; 
// The second 1's next greater number needs to search circularly, which is also 2.
// Note: The length of given array won't exceed 10000.

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,-1);
        vector<int> vis(n,0);
        stack<pair<int,int> > st;
        if(n==0) return ans;
        for(int i=0;i<n;i++)
        {
            if(st.size()==0)
            {
                st.push(make_pair(nums[i],i));
                continue;
            }
            if(st.top().first<nums[i])
            {
                while(st.top().first<nums[i])
                {
                    ans[st.top().second]=nums[i];
                    st.pop();
                    if(st.size()==0) break;
                }
            }
            st.push(make_pair(nums[i],i));
        }
        for(int i=0;i<n-1;i++)
        {
            if(st.size()==0)
            {
                st.push(make_pair(nums[i],i));
                continue;
            }
            if(st.top().first<nums[i])
            {
                while(st.top().first<nums[i])
                {
                    ans[st.top().second]=nums[i];
                    st.pop();
                    if(st.size()==0) break;
                }
            }
            st.push(make_pair(nums[i],i));
        }
        return ans;
    }
};