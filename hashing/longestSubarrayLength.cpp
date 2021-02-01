// Problem Description

// Given an integer array A of size N containing 0's and 1's only.

// You need to find the length of the longest subarray having count of 1’s one more than count of 0’s.



// Problem Constraints
// 1 <= N <= 105



// Input Format
// First and only argument is an integer array A of size N.



// Output Format
// Return an integer denoting the longest length of the subarray.



// Example Input
// Input 1:

//  A = [0, 1, 1, 0, 0, 1]
// Input 2:

//  A = [1, 0, 0, 1, 0]


// Example Output
// Output 1:

//  5
// Output 2:

//  1


// Example Explanation
// Explanation 1:

//  Subarray of length 5, index 1 to 5 i.e 1, 1, 0, 0, 1. Count of 1 = 3, Count of 0 = 2.
// Explanation 2:

//  Subarray of length 1 will be only subarray that follow the above condition.

int Solution::solve(vector<int> &a) {
    unordered_map<int,int> m;
    int n=a.size();
    int sum=0;
    int ans=0;
    m[1]=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==0) sum-=1;
        else sum+=1;
        if(m[sum]==0) m[sum]=i+1;
        if(sum==1)
        {
         ans=max(ans,i+1); continue;}
        int tp=sum-1;
        if(m[tp]!=0)
          ans=max(ans,i+1-m[tp]);
    }
    
    return ans;
}
