// 189. Rotate Array
// Medium

// 4686

// 937

// Add to List

// Share
// Given an array, rotate the array to the right by k steps, where k is non-negative.

 

// Example 1:

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]
// Example 2:

// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// Explanation: 
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]
 

// Constraints:

// 1 <= nums.length <= 105
// -231 <= nums[i] <= 231 - 1
// 0 <= k <= 105
 

// Follow up:

// Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
// Could you do it in-place with O(1) extra space?

Approach 1 : make cyclic shifts
class Solution {
public:
    void rotate(vector<int>& a, int k) {
        int n=a.size();
        if(n==1 || k==0){
            return;
        }
        k = k%n; // if k>n we would just shift by remainder as shifting n times makes same arraya again
        int count = 0; // count for the numbers shifted till now
          for(int i=0;count<n;i++){
            int tp=i;
            int temp=a[i];
            do
            {
             int tpp=a[(tp+k)%n];
             a[(tp+k)%n]=temp;
                temp=tpp;
                tp=(tp+k)%n;
                count++;
                
            }while(tp!=i);
          }
    }
       
      
        
    
};


Approach 2 (Reverse array then reverse k and n-k part)