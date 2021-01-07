// code+ contest TA question
// Montu and Inder are going to have a competition for which two teams are required to be made, obviously, the team with more power wins and if both have the same power then its a tie.
// There is a total of n students in the school and the capability of the ith student is given as a[i]. Power of a team equal to the xor of capabilities of all the students of that team.
// As a principal of the school you need to be fair so you ensure that the distribution of the team takes place in all the possible ways using all the n students .i.e. a student must be part of either Montu or of Inder's team.
// Print the number of times Montu wins followed by the number of times it's a tie. As the answer can be huge , output it modulo 10^9 +7.


// Note:- if a team has no player means its power is 0.


// Input:-
// The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
// The first line of each test case contains a single integer N.
// N lines follow. For each valid i, the i-th of these lines contains an integer Ai
// Output:-
// For each test case, print a single line containing two space separated integer ― the number of wins of Montu and the number of Ties.
// Constraints:-

// 1 ≤ T ≤ 10

// 1 ≤ N ≤  2*10^5

// 0 ≤ Ai ≤ 2^30 for each valid i

 

// SAMPLE INPUT 
// 1
// 1
// 5
// SAMPLE OUTPUT 
// 1 0
// Explanation
// Their are in total 2 cases , the student in Montu's team or in the other team.

// When in Montu's team then his team wins , in othercase Montu looses. And no case of tie

// Pranav Singhal (IIIT-ALLAHABAD)
// May the Force be with You :)
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vll vector<ll>
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL); cout.tie(NULL);}
#define nl "\n"
ll bin(ll x, ll y, ll p)  
{  
    ll res = 1;     // Initialize result  
  
    x = x % p; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % p;  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (x*x) % p;  
    }  
    return res;  
}  
int main()
{
  send help
  #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
  #endif
  ll t;cin>>t;
  while(t--)
  {
    ll n;cin>>n;
    ll xo=0;
    ll x;
    for(ll i=0;i<n;i++)
    {
      cin>>x;
      xo=xo^x;
    }
    if(xo==0) // all ties
    {
      cout<<0<<" "<<bin(2,n,mod)%mod<<nl;
    }
    else // no tie 
      cout<<bin(2,n-1,mod)%mod<<" "<<0<<nl;
  }
   
    
  return 0;
}