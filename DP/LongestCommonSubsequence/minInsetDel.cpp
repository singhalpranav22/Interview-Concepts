// Given two strings str1 and str2. The task is to remove or insert the minimum number of characters from/in str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.

// Example 1:

// Input: str1 = "heap", str2 = "pea"
// Output: 3
// Explanation: 2 deletions and 1 insertion
// p and h deleted from heap. Then, p is 
// inserted at the beginning One thing to 
// note, though p was required yet it was 
// removed/deleted first from its position 
// and then it is inserted to some other 
// position. Thus, p contributes one to the 
// deletion_count and one to the 
// insertion_count.
// Example 2:

// Input : str1 = "geeksforgeeks"
// str2 = "geeks"
// Output: 8
// Explanation: 8 insertions
 

// Your Task:
// You don't need to read or print anything. Your task is to complete the function minOperations() which takes both strings as input parameter and returns the minimum number of operation required.

// Expected Time Complexity: O(|str1|*|str2|)
// Expected Space Complexity: O(|str1|*|str2|)

// Constraints:
// 1 ≤ |str1|, |str2| ≤ 1000
// All the characters are lower case English alphabets


#include <bits/stdc++.h>
using namespace std;



#define ll long long
class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	    ll m=str1.length();
	    ll n=str2.length();
	    ll dp[m+1][n+1];
	    memset(dp,0,sizeof(dp));
	    for(ll i=1;i<=m;i++)
	    {
	        for(ll j=1;j<=n;j++)
	        {
	            if(str1[i-1]==str2[j-1])
	              dp[i][j]=dp[i-1][j-1]+1;
	             else
	             {
	                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	             }
	        }
	    }
	    ll deletions=m-dp[m][n]; // delettion in str1 to make it LCS
	    ll insertions=n-dp[m][n]; // Insertions that need to be done in str1
	    return deletions+insertions;
	    
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends