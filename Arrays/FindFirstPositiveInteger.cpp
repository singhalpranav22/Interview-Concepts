//  Given an unsorted integer array, find the first missing positive integer.

// Example:

// Given [1,2,0] return 3,

// [3,4,-1,1] return 2,

// [-8, -7, -6] returns 1

// Your algorithm should run in O(n) time and use constant space.

// // Ans would lie between 1 & n+1 as you can see, so use the swap sort technique to do this question!
int Solution::firstMissingPositive(vector<int> &a) {
    int n=a.size();
    for(int i=0;i<n;i++)
    {
       while(a[i]>0 && a[i]<n+1 && a[i]!=i+1 )
       {
           if(a[a[i]-1]==a[i]) break;
           swap(a[a[i]-1],a[i]);
       }
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]!=i+1) return i+1;
    }
}
