// Low bound and upper bound in STL
// upper_bound() and lower_bound() are standard library functions in C++.
// upper_bound() returns an iterator pointing to the first element in the range [first, last) that is greater than the value. If no such an element is found, return end().
// lower_bound() returns an iterator pointing to the first element in the range [first, last) which is greater or equal to the value. If no such an element is found, return end().

// Problem Description

// Given an sorted array A of size N. Find number of elements which are less than or equal to B.

// NOTE: Expected Time Complexity O(log N)



// Problem Constraints
// 1 <= N <= 106

// 1 <= A[i], B <= 109



// Input Format
// First agument is an integer array A of size N.

// Second argument is an integer B.



// Output Format
// Return an integer denoting the number of elements which are less than or equal to B.



// Example Input
// Input 1:

//  A = [1, 3, 4, 4, 6]
//  B = 4
// Input 2:

//  A = [1, 2, 5, 5]
//  B = 3


// Example Output
// Output 1:

//  4
// Output 2:

//  2


// Example Explanation
// Explanation 1:

//  Elements (1, 3, 4, 4) are less than or equal to 4.
// Explanation 2:

//  Elements (1, 2) are less than or equal to 3.

// One line code :
int Solution::solve(vector &a, int b) {
auto itr= upper_bound(a.begin(),a.end(),b);
return itr-a.begin();
}
// Big code

int search(vector<int> a,int b,int l,int r)
{
    int mid=(l+r)/2;
    if(a[mid]==b) return mid;
    if(mid==a.size()-1 && a[mid]<b)
      return mid;
    if(mid==0 && a[mid]>b) return -1;
    if(mid+1<a.size() && a[mid]<b && a[mid+1]>b)
     return mid;
    if(mid-1>=0 && a[mid]>b && a[mid-1]<b) 
     return mid-1;
    if(b<a[mid])
    {
       return search(a,b,l,mid-1);
    }
    if(b>a[mid])
    {
        return search(a,b,mid+1,r);
    }
   return -1;  
}
int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    int ind=search(A,B,0,n-1);
    if(A[ind]==B){
    while(ind<n && A[ind]==B) ind++;
    return ind;
    }
    return ind+1;
}
