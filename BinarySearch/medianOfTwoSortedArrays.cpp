// This question makes sense if you understand the logic behind it.
// Refer : https://www.youtube.com/watch?v=LPFhl65R7ww
// 4. Median of Two Sorted Arrays
// Hard

// 10186

// 1542

// Add to List

// Share
// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

 

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
// Example 3:

// Input: nums1 = [0,0], nums2 = [0,0]
// Output: 0.00000
// Example 4:

// Input: nums1 = [], nums2 = [1]
// Output: 1.00000
// Example 5:

// Input: nums1 = [2], nums2 = []
// Output: 2.00000
 

// Constraints:

// nums1.length == m
// nums2.length == n
// 0 <= m <= 1000
// 0 <= n <= 1000
// 1 <= m + n <= 2000
// -106 <= nums1[i], nums2[i] <= 106

class Solution {
public:
  
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        if(m>n) return findMedianSortedArrays(nums2,nums1);
        int l=0,r=m;
        while(l<=r){
            int aHalf = (l+r)/2;
            int bHalf = (m+n+1)/2 - aHalf;
            int mxA = (aHalf==m) ? INT_MAX : nums1[aHalf];
            int mnA = (aHalf==0) ? INT_MIN : nums1[aHalf-1];
            int mxB = (bHalf==n) ? INT_MAX : nums2[bHalf];
            int mnB = (bHalf==0) ? INT_MIN : nums2[bHalf-1];
            if(mnA<=mxB && mnB<=mxA)
            {
                if((m+n)%2==1){
                    double ans = max(mnA,mnB);
                    return ans;
                }
                else{
                    double ans = (double)(max(mnA,mnB)+min(mxA,mxB))/2;
                    return ans;
                }
            }
            if(mnA>mxB){
                r=aHalf-1;
            }
            else
                l=aHalf+1;
        }
        return -1.0;
    }
};