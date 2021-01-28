// Problem Description

// Given an one-dimensional unsorted array A containing N integers.

// You are also given an integer B, find if there exists a pair of elements in the array whose difference is B.

// Return 1 if any such pair exists else return 0.



// Problem Constraints
// 1 <= N <= 105
// -103 <= A[i] <= 103
// -105 <= B <= 105


// Input Format
// First argument is an integer array A of size N.

// Second argument is an integer B.



// Output Format
// Return 1 if any such pair exists else return 0.



// Example Input
// Input 1:

//  A = [5, 10, 3, 2, 50, 80]
//  B = 78
// Input 2:

//  A = [-10, 20]
//  B = 30


// Example Output
// Output 1:

//  1
// Output 2:

//  1


// Example Explanation
// Explanation 1:

//  Pair (80, 2) gives a difference of 78.
// Explanation 2:

//  Pair (20, -10) gives a difference of 30 i.e 20 - (-10) => 20 + 10 => 30

int Solution::solve(vector<int> &A, int B) {
if(A.empty()) return 0;
int N = A.size() - 1;
sort(A.begin(), A.end());

        // We are doing A[j] - A[i]. So if diff < B we must inc A[j]. So j++
        //And if diff > B we should i ++
        //Takes care of both cases : B +ve and -ve
        int i = 0, j = 1, diff = 0;
        while(i <= N && j <=N){
            diff = A[j] - A[i];
            if(i != j && diff == B) return 1;
            else if(diff < B) j++;
            else i++;
        }
        return 0;
        
    }