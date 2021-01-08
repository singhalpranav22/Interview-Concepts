// Given an integer array A of N integers, find the pair of integers in the array which have minimum XOR value. Report the minimum XOR value.

// Input Format:

//     First and only argument of input contains an integer array A
// Output Format:

//     return a single integer denoting minimum xor value
// Constraints:

// 2 <= N <= 100 000  
// 0 <= A[i] <= 1 000 000 000
// For Examples :

// Example Input 1:
//     A = [0, 2, 5, 7]
// Example Output 1:
//     2
// Explanation:
//     0 xor 2 = 2
// Example Input 2:
//     A = [0, 4, 7, 9]
// Example Output 2:
//     3

// Code using property that : when numbers belong to the same xor range that there xor is 
// difference of the numbers themselves like 5^7=2=7-5

int Solution::findMinXor(vector<int> &a) {
    int mn=INT_MAX;
    int n=a.size();
    sort(a.begin(),a.end());
    for(int i=1;i<n;i++)
    {
     mn=min(a[i-1]^a[i],mn);   
    }
    return mn;
}
