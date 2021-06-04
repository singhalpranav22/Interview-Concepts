// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
// Example 3:

// Input: nums = [1], target = 0
// Output: -1
 

// Constraints:

// 1 <= nums.length <= 5000
// -104 <= nums[i] <= 104
// All values of nums are unique.
// nums is guaranteed to be rotated at some pivot.
// -104 <= target <= 104

class Solution {
public:
    int search(vector<int>& v, int t) {
        int pivot; // index which is starting of the array (smallest element)
        int n=v.size();
        if(n==1){
            if(v[0]==t) return 0;
            else return -1;
        }
        int l=0,r=n-1;
        while(l<r){
            if(v[l]<=v[r]) {
                cout<<l<<" "<<r<<endl;
                pivot=l;break;} // in sorted array half, first index is pivot
            int mid=l-(l-r)/2;
            if(v[mid]<v[(mid-1+n)%n] &&v[mid]<v[(mid+1)%n]){ // found the pivot (%n for taking care of bounds)
                cout<<mid<<endl;
                pivot = mid;
                break;
            }
            if(v[mid]>v[r]) {  // go to unsorted half as pivot would be there only
                l=mid+1;
            }
            else if(v[mid]<v[l]){  // go to unsorted half
                r=mid-1;
            }
            
        }
        cout<<pivot<<endl;
        l=0,r=pivot-1;
        bool f=false;
        int ans=0;
        while(l<=r){
            int mid = l-(l-r)/2;
            if(v[mid]==t) {
                f=true;
                ans=mid;
                break;
            }
            if(v[mid]<t) l=mid+1;
            else r=mid-1;
        }
        if(f) return ans;
        l=pivot,r=n-1;
        while(l<=r){
            int mid = l-(l-r)/2;
            if(v[mid]==t){
                f=true;
                ans=mid;
                break;
            }
            if(v[mid]<t) l=mid+1;
            else r=mid-1;
        }
        if(f) return ans;
        else return -1;
    }
};