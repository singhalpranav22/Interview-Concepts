// This solution gives TLE on LeetCode
// It should be optimised more by using binary search

// You are given K eggs, and you have access to a building with N floors from 1 to N. 

// Each egg is identical in function, and if an egg breaks, you cannot drop it again.

// You know that there exists a floor F with 0 <= F <= N such that any egg dropped at a floor higher than F will break, and any egg dropped at or below floor F will not break.

// Each move, you may take an egg (if you have an unbroken one) and drop it from any floor X (with 1 <= X <= N). 

// Your goal is to know with certainty what the value of F is.

// What is the minimum number of moves that you need to know with certainty what F is, regardless of the initial value of F?

 

// Example 1:

// Input: K = 1, N = 2
// Output: 2
// Explanation: 
// Drop the egg from floor 1.  If it breaks, we know with certainty that F = 0.
// Otherwise, drop the egg from floor 2.  If it breaks, we know with certainty that F = 1.
// If it didn't break, then we know with certainty F = 2.
// Hence, we needed 2 moves in the worst case to know what F is with certainty.
// Example 2:

// Input: K = 2, N = 6
// Output: 3
// Example 3:

// Input: K = 3, N = 14
// Output: 4

// MCM format dp
class Solution {
public:
    int dp[102][10005];
     
    int find(int k,int n)
    {
         int ans=INT_MAX;
         if(k==1 || n<=1) return n; // base case with 1 egg or on first floor
        if(dp[k][n]!=-1) return dp[k][n];
        for(int i=1;i<=n;i++) // i represents floor at which egg is dropped or not dropped
        {
            int tmp;
            // case 1 if egg breaks check floors below
            int brk;
            if(dp[k-1][i-1]==-1)
            {
                brk=find(k-1,i-1);
                dp[k-1][i-1]=brk;
            }
            else
            {
                brk=dp[k-1][i-1];
            }
            
            // case 2 if egg doesn't break check floors above it
            int nbrk;
            if(dp[k][n-i]==-1)
            {
                nbrk=find(k,n-i);
                dp[k][n-i]=nbrk;
            }
            else{
                nbrk=dp[k][n-i];
            }
            tmp=max(brk,nbrk)+1; // max for finding worst case, +1 as it's an additional experiment
            ans=min(ans,tmp);
            
        }
        return dp[k][n]=ans;
        
    }
    int superEggDrop(int k, int n) {
       
        memset(dp,-1,sizeof(dp));
        return find(k,n);
    }
};