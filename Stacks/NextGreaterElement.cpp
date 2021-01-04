// You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

// The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.

// Example 1:
// Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
// Output: [-1,3,-1]
// Explanation:
//     For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
//     For number 1 in the first array, the next greater number for it in the second array is 3.
//     For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
// Example 2:
// Input: nums1 = [2,4], nums2 = [1,2,3,4].
// Output: [3,-1]
// Explanation:
//     For number 2 in the first array, the next greater number for it in the second array is 3.
//     For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
// Note:
// All elements in nums1 and nums2 are unique.
// The length of both nums1 and nums2 would not exceed 1000.

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<pair<int,int> > st;
        int n=nums2.size();
        int msz=nums1.size();
        if(n==0 || msz==0)
        {
            vector<int> ans;
            return ans;
        }
        int a[n];// for storing results
        memset(a,-1,sizeof(a));
        for(int i=0;i<n;i++)
        {
            if(st.size()==0)
            {
                st.push(make_pair(nums2[i],i));
                continue;
    
            }
            if(st.top().first<nums2[i])
            {
                while(  st.top().first<nums2[i] )
                {
                a[st.top().second]=nums2[i];
                st.pop();
                    if(st.size()==0) break;
                }
                
            }
             st.push(make_pair(nums2[i],i));
        }
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
            m[nums2[i]]=i;
        vector<int> ans;
        for(int i=0;i<nums1.size();i++)
        {
            ans.push_back(a[m[nums1[i]]]);
        }
        return ans;
        
    }
};