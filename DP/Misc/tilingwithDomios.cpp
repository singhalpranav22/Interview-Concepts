// Example Input
// Input 1:

//  2
// Input 2:

//  1


// Example Output
// Output 1:

//  3
// Output 2:

//  0


// Example Explanation
// Explanation 1:

//  Following are all the 3 possible ways to fill up a 3 x 2 board.
 
// Explanation 2:

//  Not a even a single way exists to completely fill the grid of size 3 x 1.

long long int dp[100009][8];
#define mod 1000000007
long long find(int i,int a,int b,int c)
{
    if(i==1 || i==0) return 1;
    int x=a*4+b*2+c;
    if(dp[i][x]!=-1) return dp[i][x]%mod;
    if(a==0 && b==0 && c==0)
    {
        return dp[i][x]=(find(i-2,0,0,0)%mod + find(i-1,1,0,0)%mod + find(i-1,0,0,1)%mod)%mod;
    }
    else if(a==1 && b==0 && c==0)
    {
        return dp[i][x]=(find(i-1,0,1,1)%mod + find(i-1,0,0,0)%mod)%mod;
    }
    else if(a==0 && b==1 && c==0)
    {
        return dp[i][x]=find(i-1,1,0,1)%mod;
    }
    else if(a==0 && b==0 && c==1)
    {
        return dp[i][x]=(find(i-1,0,0,0)%mod + find(i-1,1,1,0)%mod)%mod;
    }
    else if(a==1 && b==1 && c==0)
    {
        return dp[i][x]=find(i-1,0,0,1)%mod;
    }
    else if(a==0 && b==1 && c==1)
    {
        return dp[i][x]=find(i-1,1,0,0)%mod;
    }
    else if(a==1 && b==0 && c==1)
    {
        return dp[i][x]=find(i-1,0,1,0)%mod;
    }
}
int Solution::solve(int A) {
    memset(dp,-1,sizeof(dp));
    if(A%2!=0) return 0; 
    return (int)find(A,0,0,0);
}
