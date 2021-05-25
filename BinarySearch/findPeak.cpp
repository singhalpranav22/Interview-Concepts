// apply binary search mid would be part of ascending or a descending series 

// 162. Find Peak Element
// Medium

// 2902

// 2701

// Add to List

// Share
// A peak element is an element that is strictly greater than its neighbors.

// Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

// You may imagine that nums[-1] = nums[n] = -∞.

// You must write an algorithm that runs in O(log n) time.

 

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 2
// Explanation: 3 is a peak element and your function should return the index number 2.
// Example 2:

// Input: nums = [1,2,1,3,5,6,4]
// Output: 5
// Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
 

// Constraints:

// 1 <= nums.length <= 1000
// -231 <= nums[i] <= 231 - 1
// nums[i] != nums[i + 1] for all valid i.

class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int n=a.size();
        int l=0,r=n-1;
        if(n==1) return 0;
        while(l<=r){
            int mid = r-(r-l)/2;
            if(mid==0){
                if(a[mid]>a[mid+1]) return mid;
                else return mid+1;
            }
            if(mid==n-1){
                if(a[mid]>a[mid-1]) return mid;
                else return mid-1;
            }
            if(a[mid-1]<a[mid] && a[mid]>a[mid+1]) return mid;
            if(a[mid-1]>a[mid]) r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};