// Given an array ‘A’ of sorted integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

//  Example: Input : 
//     A : [1 3 5] 
//     k : 4
//  Output : YES as 5 - 1 = 4 
// Return 0 / 1 ( 0 for false, 1 for true ) for this problem

// Try doing this in less than linear space complexity.

int Solution::diffPossible(vector<int> &A, int B) {
    int n=A.size();
    int i=0,j=1;
    while(i<n && j<n)
    {
        if(A[j]-A[i]==B && i!=j)
        {
            return 1;
        }
        if(A[j]-A[i]>B)
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return 0;
}
