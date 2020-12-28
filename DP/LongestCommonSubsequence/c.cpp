#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &a) {
    sort(a.begin(),a.end());
    int n=a.size();
    int dp[n];
    dp[n-1]=0;
    int toll=0;
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]<a[i+1])
        {
         dp[i]=dp[i+1]+1+toll;
         toll=0;
        }
         else if(a[i]==a[i+1])
         {
          dp[i]=dp[i+1];toll++;
         }
    }
    int ans=-1;
    for(int i=0;i<n;i++)
     {
         cout<<a[i]<<" ";
         if(dp[i]==a[i]){
             ans=1;
            
         }
     }
     cout<<endl;
     for(int i=0;i<n;i++) cout<<dp[i]<<" ";
     cout<<endl;
     return ans;
}
int main(){
    vector<int> v {4, -9, 8, 5, -1, 7, 5, 3};
cout<<solve(v);
}