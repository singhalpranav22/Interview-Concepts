// Problem Description

// You are given a 1D integer array B containing A integers.

// Count the number of ways to split all the elements of the array into 3 contiguous parts so that the sum of elements in each part is the same.

// Such that : sum(B[1],..B[i]) = sum(B[i+1],...B[j]) = sum(B[j+1],...B[n])



// Problem Constraints
// 1 <= A <= 105

// -109 <= B[i] <= 109



// Input Format
// First argument is an integer A.

// Second argument is an 1D integer array B of size A.



// Output Format
// Return a single integer denoting the number of ways to split the array B into three parts with the same sum.



// Example Input
// Input 1:

//  A = 5
//  B = [1, 2, 3, 0, 3]
// Input 2:

//  A = 4
//  B = [0, 1, -1, 0]


// Example Output
// Output 1:

//  2
// Output 2:

//  1

// sum of array should be divisible by 3 
// First part second part should be 2*sum/3
int Solution::solve(int A, vector<int> &B) {
    int sum=0;
    for(int i=0;i<A;i++) sum+=B[i];
    if(sum%3!=0) return 0;
    int frst=sum/3;
    int sc=frst*2;
    int fhlf=0;
    int tmp=0;
    int ans=0;
    int fct=0;
    if(sum==0)
    {
        for(int i=0;i<A-1;i++){
        tmp+=B[i];
        if(tmp==0) {ans+=fct;fct++;}
        
        }
        return ans;
    }
    for(int i=0;i<A-1;i++)
    {
      tmp+=B[i];
      if(tmp==frst) fct++;
      if(tmp==sc) ans+=fct;
    }
    return ans;
}
