// Given an unsorted integer array nums, find the smallest missing positive integer.

// Follow up: Could you implement an algorithm that runs in O(n) time and uses constant extra space.?

 

// Example 1:

// Input: nums = [1,2,0]
// Output: 3
// Example 2:

// Input: nums = [3,4,-1,1]
// Output: 2
// Example 3:

// Input: nums = [7,8,9,11,12]
// Output: 1
 

// Constraints:

// 0 <= nums.length <= 300
// -231 <= nums[i] <= 231 - 1

// Swap Sort technique is used which uses O(n) time & does not use any extra space
class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
       int n=v.size();
        // Answer would be between [1,...,n+1]
        int i=0;
        while(i<n)
        {
            while(v[i]!=i+1 && (v[i]>=1 && v[i]<=n))
            {
                if(v[v[i]-1]==v[i])
                     break;
                else
                    swap(v[v[i]-1],v[i]);           
            }
            i++;
        }
        for(int i=0;i<n;i++)
        {
            if(v[i]!=i+1) return i+1;
        }
        return n+1;
    }
};
