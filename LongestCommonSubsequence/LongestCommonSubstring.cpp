// Given two strings X and Y. The task is to find the length of the longest common substring.
// Constraints:
// 1 <= T <= 200
// 1 <= N, M <= 100

// Example:
// Input:
// 2
// 6 6
// ABCDGH
// ACDGHR
// 3 2
// ABC
// AC

// Output:
// 4
// 1

// Example:
// Testcase 1: CDGH is the longest substring present in both of the strings.
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	//code
	ll t;cin>>t;
	while(t--){
	    ll n,m;cin>>n>>m;
	    ll dp[n+1][m+1];
	    string a,b;cin>>a>>b;
	    memset(dp,0,sizeof(dp));
	    ll ans=0;
	    for(ll i=0;i<=n;i++){ // Initialisation of first row and first column
	        for(ll j=0;j<=m;j++)
	         if(i==0 || j==0) dp[i][j]=0;
	    }
	   
	    for(ll i=1;i<=n;i++){
	        for(ll j=1;j<=m;j++){
	            if(a[i-1]==b[j-1])
	               dp[i][j]=dp[i-1][j-1]+1;
	           else
	             dp[i][j]=0; // when characters not equal that continuity is broken and the length of the substring is 0 from that point onwards
	             
	             if(ans<dp[i][j]) ans=dp[i][j];
	        }
	    }
	    cout<<ans<<"\n";
	      
	}
	return 0;
}