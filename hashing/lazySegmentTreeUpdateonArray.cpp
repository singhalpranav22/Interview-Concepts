// // You have given N plates each plate contains some number of fruits. You will be given Q queries of type: add X number of fruits in each plate from L to R.
// After completing all the queries, print the maximum number of fruits among all the plates.
Input
6
3 2 5 6 1 4
2
10 2 4
9 1 5
Output
25

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	 int h[n+3];
	 for(int i=0;i<=n+2;i++) h[i]=0;
	 int q;
	 cin>>q;
	 while(q--)
	 {
		 int x,l,r;cin>>x>>l>>r;
		 l++;
		 r++;
		 if(l>r) swap(l,r);
		 h[l]+=x;
		 h[r+1]-=x;
	 }
	 for(int i=1;i<=n;i++) h[i]+=h[i-1];
	 for(int i=1;i<=n;i++) a[i]+=h[i];
	 int ans=INT_MIN;
	 for(int i=1;i<=n;i++) ans=max(ans,a[i]);
	 cout<<ans;
}