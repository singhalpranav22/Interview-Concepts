// Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
// For Example:
// ab: Number of insertions required is 1. bab or aba
// aa: Number of insertions required is 0. aa
// abcd: Number of insertions required is 3. dcbabcd

// Input:

// The first line of input contains an integer T denoting the number of test cases.
// The first line of each test case is S.

// Output:

// Print the minimum number of characters.

// Constraints:

// 1 ≤ T ≤ 50
// 1 ≤ S ≤ 40

// Example:

// Input:
// 3
// abcd
// aba
// geeks

// Output:
// 3
// 0
// 3

#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int main() {
	//code
	int t;cin>>t;
	while(t--)
	{
	    string s;cin>>s;
	    int n=s.length();
	    memset(dp,0,sizeof(dp));
	    string a;
	    for(int i=0;i<=n;i++) a+=s[i];
	    reverse(s.begin(),s.end());
	    string b=s; // reverse of s
	   
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=n;j++)
	        {
	            if(a[i-1]==b[j-1])
	            dp[i][j]=dp[i-1][j-1]+1;
	            else
	             dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	        }
	    }
	    
	    int ans=n-dp[n][n];
	    cout<<ans<<endl;
	    
	    
	}
	return 0;
}