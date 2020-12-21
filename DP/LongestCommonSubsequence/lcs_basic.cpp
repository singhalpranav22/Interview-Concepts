
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;
// Iterative version of LCS
// function to find longest common subsequence
#define ll long long

int lcs(int, int, string, string);

int main()
{
    int t,n,k,x,y;
    
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        
        cout << lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
// } Driver Code Ends


int lcs(int x, int y, string s1, string s2){
    
    // your code here
    ll dp[x+1][y+1];
    memset(dp,-1,sizeof(dp));
    for(ll i=0;i<=x;i++)
    {
        for(ll j=0;j<=y;j++)
        {
            if(i==0 || j==0)
              dp[i][j]=0;
        }
    }
    for(ll i=1;i<=x;i++)
    {
        for(ll j=1;j<=y;j++)
        {
            if(s1[i-1]==s2[j-1])
               dp[i][j]=dp[i-1][j-1]+1;
            else
              dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    ll i=x,j=y;
    string ans; // for printing the LCS
    while(i>0 && j>0) 
    {
      if(s1[i-1]==s2[j-1]){
       ans+=s1[i-1];
       i--;j--;
      }
      else
      {
          if(dp[i-1][j]>dp[i][j-1])
               i=i-1;
        else
          j=j-1;
      }
        
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<"\n";
    return dp[x][y];
    
}
