Problem Description

Given a bitonic sequence A of N distinct elements, write a program to find a given element B in the bitonic sequence in O(logN) time.

NOTE:

A Bitonic Sequence is a sequence of numbers which is first strictly increasing then after a point strictly decreasing.


Problem Constraints
3 <= N <= 105

1 <= A[i], B <= 108

Given array always contain a bitonic point.

Array A always contain distinct elements.



Input Format
First argument is an integer array A denoting the bitonic sequence.

Second argument is an integer B.



Output Format
Return a single integer denoting the position (0 index based) of the element B in the array A if B doesn't exist in A return -1.




 int Solution::solve(vector <int> &v, int t) {
 int n=v.size();
 int l=0,r=n-1;
 int pivot;
 while(l<=r){ // find peak element
     int mid = l-(l-r)/2;
     if((mid>0 && v[mid]>v[mid-1]) && (mid<n-1 && v[mid]>v[mid+1])){
         pivot=mid;
         break;
     }
     if(mid>0 && v[mid-1]>v[mid]) r=mid-1;
     else l=mid+1;
 }
 l=0,r=pivot;
 while(l<=r){
     int mid = l - (l-r)/2;
     if(v[mid]==t) return mid;
     if(v[mid]<t) l=mid+1;
     else r=mid-1;
 }
 l=pivot+1,r=n-1;
 while(l<r){
     int mid = l - (l-r)/2;
     if(v[mid]==t) return mid;
     if(v[mid]>t) l=mid+1;
     else r=mid-1;
 }
 return -1;
}
