// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
// Example 3:

// Input: nums = [], target = 0
// Output: [-1,-1]
 

// Constraints:

// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109
// nums is a non-decreasing array.
// -109 <= target <= 109

class Solution {
public:
    // lower_bound implementation is here
    int lowerBound(vector<int> v,int target,int n){
        int l=0,r=n-1;
        int mid;
        while(l<=r){
            mid = r-(r-l)/2;
            if(v[mid]<target) l=mid+1;
            else r=mid-1;
        }
        return l;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1,-1};
        int n=nums.size();
        int low=lowerBound(nums,target,n);
        int high=lowerBound(nums,target+1,n);
        if(low>=0 && low<n && nums[low]==target){
            return {low,high-1};
        }
        else return {-1,-1};
    }
};