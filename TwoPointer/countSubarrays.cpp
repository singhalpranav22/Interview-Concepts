// Problem Description

// Given an array A of N non-negative numbers and you are also given non-negative number B.

// You need to find the number of subarrays in A having sum less than B. We may assume that there is no overflow.



// Problem Constraints
// 1 <= N <= 104

// 1 <= A[i] <= 100

// 1 <= B <= 108



// Input Format
// First argument is an integer array A.

// Second argument is an integer B.



// Output Format
// Return an integer denoting the number of subarrays in A having sum less than B.



// Example Input
// Input 1:

//  A = [2, 5, 6]
//  B = 10
// Input 2:

//  A = [1, 11, 2, 3, 15]
//  B = 10


// Example Output
// Output 1:

//  4
// Output 2:

//  4


// Example Explanation
// Explanation 1:

//  The subarrays with sum less than B are {2}, {5}, {6} and {2, 5},
// Explanation 2:

//  The subarrays with sum less than B are {1}, {2}, {3} and {2, 3}

int Solution::solve(vector<int> &A, int B) {
    int ans=0;
    int n=A.size();
    int i=0,j=0;
    int curr=A[0];
    while(i<n && j<n){
        if(curr<B)
        {
            ans+=(j-i+1);
            j++;
            curr+=A[j];
        }
        else{
            curr-=A[i];
            i++;
        }
    }
    return ans;
}
