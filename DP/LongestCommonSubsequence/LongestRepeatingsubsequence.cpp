// Given a string str, find length of the longest repeating subseequence such that the two subsequence don’t have same string character at same position, i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.

// Input:

// The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer N denoting the length of string str.

// The second line of each test case contains the string str consisting only of lower case english alphabets.

// Output:

// Print the length of the longest repeating subsequence for each test case in a new line.


// Constraints:

// 1<= T <=100

// 1<= N <=1000


// Example:

// Input:

// 2

// 3

// abc

// 5

// axxxy

// Output:

// 0

// 2

#include <bits/stdc++.h>
using namespace std;

int dp[1004][1004];
int main() {
	//code
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    string s;
	    cin>>s;
	    memset(dp,0,sizeof(dp));
	    for(int i=1;i<=n;i++) // Simple LCS between the same string such that chars in same position are not counted
	    {
	        for(int j=1;j<=n;j++)
	        {
	            if(s[i-1]==s[j-1] && i!=j)
	             dp[i][j]=dp[i-1][j-1]+1;
	             else
	             dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	        }
	    }
	     cout<<dp[n][n]<<endl;
	    
	}
	return 0;
}