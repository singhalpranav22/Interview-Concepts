// Remove Element

// Given an array and a value, remove all the instances of that value in the array.
// Also return the number of elements left in the array after the operation.
// It does not matter what is left beyond the expected length.

//  Example:
// If array A is [4, 1, 1, 2, 1, 3]
// and value elem is 1,
// then new length is 3, and A is now [4, 2, 3] 
// Try to do it in less than linear additional space complexity.

int Solution::removeElement(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=A.size(),i=0,j=0; // i for poistion of the index where we have to put and j is the comparison pointer
    while(j<n){
    if(A[j]!=B){
        A[i]=A[j];
        i++;
    }
    j++;
}
return(i);
    
}
