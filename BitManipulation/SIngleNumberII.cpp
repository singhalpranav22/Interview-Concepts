// Given an array of integers, every element appears thrice except for one which occurs once.

// Find that element which does not appear thrice.

// Note: Your algorithm should have a linear runtime complexity.

// Could you implement it without using extra memory?

// Input Format:

//     First and only argument of input contains an integer array A
// Output Format:

//     return a single integer.
// Constraints:

// 2 <= N <= 5 000 000  
// 0 <= A[i] <= INT_MAX
// For Examples :

// Example Input 1:
//     A = [1, 2, 4, 3, 3, 2, 2, 3, 1, 1]
// Example Output 1:
//     4
// Explanation:
//     4 occur exactly once
// Example Input 2:
//     A = [0, 0, 0, 1]
// Example Output 2:
//     1

// count the number of 1's or 0's at the ith place and if that is not divisible by 3 than include that power of two in the ans
int Solution::singleNumber(const vector<int> &a) {
    long long ans=0;
    int odd=0,even=0;
    int n=a.size();
    long long p=1; // representing power of two
    for(int i=0;i<32;i++)  // O(32*n) 32 bits in int data type
    {
        odd=0;
        even=0;
        for(int j=0;j<n;j++)
        {
            if(a[j]&p) odd++;
            else even++;
        }
        if(odd%3!=0) // to check if the set bit at the current i position is divisble by 3 or not
          ans+=p; // include that power of 2 in the ans
        p=p*2; // increase the power of 2
    }
    return (int)ans;
}
