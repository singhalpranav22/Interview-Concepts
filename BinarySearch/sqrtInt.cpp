// Given an integar A.

// Compute and return the square root of A.

// If A is not a perfect square, return floor(sqrt(A)).

// DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY



// Input Format

// The first and only argument given is the integer A.
// Output Format

// Return floor(sqrt(A))
// Constraints

// 1 <= A <= 10^9
// For Example

// Input 1:
//     A = 11
// Output 1:
//     3

// Input 2:
//     A = 9
// Output 2:
//     3
 #define ll long long
 ll ans[100001];
int binary(int l,int r, ll arr[],ll x)
{
    if(l>r)
    {
        return -1;
    }
    int mid=l+(r-l)/2;
    // cout<<mid<<nl;
    if(arr[mid]==x)
    return mid;
    
    if(mid>=1 && arr[mid-1]<x  && arr[mid]>x)
    return mid-1;
    
    if(arr[mid]<x)
    return binary(mid+1,r,arr,x);
    
    if(arr[mid]>x){
    
    return binary(l,mid-1,arr,x);
    }
}
int Solution::sqrt(int a) {
  
    for(ll i=0;i<=100000;i++)
    {
        ans[i]=i*i;
    }
    // cout<<ans[50000]<<nl;
    return binary(0,100000,ans,(ll)a);
}