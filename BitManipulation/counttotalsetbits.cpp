// Problem Description

// Given a positive integer A, the task is to count the total number of set bits in the binary representation of all the numbers from 1 to A.

// Return the count modulo 109 + 7.



// Problem Constraints
// 1 <= A <= 109
// Write number for n=12, from 1 to 12 and deduce the formula
// Formula:
// First calculate the set bit behind the number log2(n). Let x=log2(n), those set bits are simply
// x*2^(x-1) + (n-2^x+1) (the most significant bits between 2^x and n) + solve(n-2^x) reduces the problem
#define mod 1000000007
#define ll long long
ll po(ll x,ll y)
{
    if(y==0) return 1;
     ll res=po(x,y/2);
    if(y&1LL){
       return (res*res*x)%mod;
    }
    else
     return (res*res)%mod;
}
int Solution::solve(int n) {
    if(n<=2) return n%mod;
    int x=log2(n);
    ll t1=((x)*(po(2,x-1)%mod))%mod;
    ll t2=n - (po(2,x)%mod) +1 ;
    return (int)(((t1+t2)%mod+solve(n-(po(2,x)%mod)))%mod);
    
}
