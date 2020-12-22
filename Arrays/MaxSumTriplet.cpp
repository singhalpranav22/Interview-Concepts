// Problem Description

// Given an array A containing N integers.

// You need to find the maximum sum of triplet ( Ai + Aj + Ak ) such that 0 <= i < j < k < N and Ai < Aj < Ak.

// If no such triplet exist return 0.



// Problem Constraints
// 3 <= N <= 105.

// 1 <= A[i] <= 108.



// Input Format
// First argument is an integer array A.



// Output Format
// Return a single integer denoting the maximum sum of triplet as described in the question.



// Example Input
// Input 1:

//  A = [2, 5, 3, 1, 4, 9]
// Input 2:

//  A = [1, 2, 3]


// Example Output
// Output 1:

//  16
// Output 2:

//  6


// Example Explanation
// Explanation 1:

//  All possible triplets are:-
//     2 3 4 => sum = 9
//     2 5 9 => sum = 16
//     2 3 9 => sum = 14
//     3 4 9 => sum = 16
//     1 4 9 => sum = 14
//   Maximum sum = 16
// Explanation 2:

//  All possible triplets are:-
//     1 2 3 => sum = 6
//  Maximum sum = 6


int Solution::solve(vector<int> &a) {
     // To be solved in O(nlogn)
     // Fix j than see left side form max that is less than a[j] & right side for element greater than a[j]
     // For right side suffix array could be made in O(n)
     // For left side elements have to be kept in set to be in sorted order and than binary search for the required element
     
     int n=a.size();
     int suff[n];
     suff[n-1]=a[n-1];
     for(int i=n-2;i>=0;i--) // making suffix array for max from right
     {
         if(a[i]>suff[i+1])
            suff[i]=a[i];
        else
         suff[i]=suff[i+1];
         
     }
     set <int> s;
     int ans=INT_MIN;
     s.insert(a[0]);
     for(int i=1;i<n-1;i++)
     {
         int rmx=suff[i+1];
         s.insert(a[i]);
         auto it=s.find(a[i]);
         
         if(it!=s.begin() && rmx>a[i])
           {
            //    cout<<(*(--it))<<" "<<a[i]<<" "<<rmx<<endl;
               ans=max(ans,((*(--it)))+a[i]+rmx);
           }
           
     }
     return ans;
}