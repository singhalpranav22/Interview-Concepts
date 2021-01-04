// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

// Example 1:


// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9
 

// Constraints:

// n == height.length
// 0 <= n <= 3 * 104
// 0 <= height[i] <= 105

// Think logically. water trapped in the ith place is the min of max heights on it's left and max on it's right including itself

// Do as directed in question. For each element in the array, we find the maximum level of water it can trap after the rain, which is equal to the minimum of maximum height of bars on both the sides minus its own height.

// Use dp here for calculating pref for max height from left and suff for max height from right

class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        if(n==0) return 0;
        int pref[n],suff[n];
        pref[0]=h[0];
        suff[n-1]=h[n-1];
        for(int i=1;i<n;i++)
        {
            if(h[i]>pref[i-1])
            {
                pref[i]=h[i];
            }
            else
                pref[i]=pref[i-1];
        }
        for(int i=n-2;i>=0;i--)
        {
            if(h[i]>suff[i+1])
                suff[i]=h[i];
            else
                suff[i]=suff[i+1];
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=min(pref[i],suff[i])-h[i];
        }
        return ans;
    }
};