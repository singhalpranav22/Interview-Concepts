// Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times.

// You may assume that the array is non-empty and the majority element always exist in the array.

// Example :

// Input : [2, 1, 2]
// Return  : 2 which occurs 2 times which is greater than 3/2. 

// Moore's Voting algorithm
int Solution::majorityElement(const vector<int> &A) {
    int n=A.size();
     int count=1;
     int currmax=A[0];
     for(int i=1;i<n;i++)
     {
         if(A[i]==currmax)
           count++;
           else count --;
           if(count==0) {currmax=A[i]; count=1;}
     }
     return currmax;
}
