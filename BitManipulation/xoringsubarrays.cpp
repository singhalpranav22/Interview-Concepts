// Problem Description

// Given an integer array A of size N.

// You need to find the value obtained by XOR-ing the contiguous subarrays, followed by XOR-ing the values thus obtained. Determine and return this value.

// For example, if A = [3, 4, 5] :

// Subarray    Operation   Result
// 3       None            3
// 4       None            4
// 5       None            5
// 3,4   3 XOR 4         7
// 4,5   4 XOR 5         1
// 3,4,5    3 XOR 4 XOR 5   2

// Now we take the resultant values and XOR them together:

// 3 ⊕ 4 ⊕ 5 ⊕ 7 ⊕ 1⊕ 2 = 6 we will return 6.



// Problem Constraints
// 1 <= N <= 105

// 1 <= A[i] <= 108



// Input Format
// First and only argument is an integer array A.



// Output Format
// Return a single integer denoting the value as described above.

// Every element occurs (i+1)*(n-1) times as say we can see this in this way lets say we have an array [start,…i,…end] now choose any element in the array say “i”. Now we have to find all the possible subarrays which can contain this element “i” in it. So now we have choose a starting index and ending index of the sub array. for the element “i” to lie in the sub array the starting index should lie between (start…i) and ending index should lie between (i,…end). So now just choose one element from both the ranges, we will get (i+1)(n-i).
int Solution::solve(vector<int> &a) {
    int n=a.size();
    vector<int> poss;
    for(int i=0;i<n;i++)
    {
        if(((i+1)*(n-i))%2!=0) // a number occurs odd number of times
            poss.push_back(a[i]);
    }
    int ans=0;
    for(int i=0;i<poss.size();i++)
    {
        ans=ans^poss[i];
    }
    return ans;
}
