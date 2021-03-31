// Question 2
// Max. score: 10
// In question 1, the students are instead arranged in an arbitrary manner in an open classroom. Let W[i,j]=W[j,i] denote the difficulty in passing a solution directly from student i to student j. For simplicity, let all students have integer roll numbers starting from 0 to n-1, where n is the number of students. Since the students are arranged in an arbitrary manner, the students pre-decide which student will send/receive solutions from which student. Assume all links are noiseless, meaning that if student i is connected to student j, then student i copies an exact replica of the solution of student j (or vice versa). Minimize the total difficulty in the network subjected to the constraints that (i) All students must be able to receive the solution from the topper (roll number 0), and (ii) The professor may stand on one connection while invigilating making it impossible for the students to cheat. Still, it should be possible for all students to get a copy of the topper’s solution.

 

// Input Format

// The first line of input is the number of test cases. For every test case, the first two integer inputs are n (the number of students) and e (the number of relations). The students are assumed to be with roll numbers starting from 0 to n-1. The next e lines contain two integers r1 and r2 and the relation between r1 and r2, or W[r1,r2]. The relation W[r2,r1] is the same and will not be given as an explicit input separately.

 

// Output Format

// The first line for every test case prints the total difficulty. The next variable number of lines print the connections that are indispensable for passing the solutions. Each line prints the integers i and j showing a connection directly passing the solution from roll number i to roll number j. Since for every i and j pair in the solution, there will also be the solution pair j and I, the rule is that for every line in the output mentioning pairs i and j, j>i. Print NIL if no solution is possible.

 

// Sample Input

// 1

// 5 7

// 0 1 5

// 0 3 6

// 1 3 10

// 1 2 13

// 3 4 8

// 3 2 11

// 2 4 7

 

// Sample Output

// 39

// 0 1

// 0 3

// 1 2

// 2 4

// 3 4

 

// Explanation

// In the following graph, even if any one edge is broken, there will be a path from 0 (topper) to all other students.



// Constraints

// Maximum Number of students = 15

// Maximum Number of relations = 15×14/2

// SAMPLE INPUT 
// 1
// 5 7
// 0 1 5
// 0 3 6
// 1 3 10
// 1 2 13
// 3 4 8
// 3 2 11
// 2 4 7
// SAMPLE OUTPUT 
// 39
// 0 1
// 0 3
// 1 2
// 2 4
// 3 4

// PRANAV SINGHAL
// IIT2019050
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

ll adj[100][1000];
bool currAdj[100][1000];
ll emin=INT_MAX;
ll ans;
vector<pair<ll,ll> > edgeAns;
void dfs(ll x,vector<ll> v[],bool vis[]){
  if(vis[x]) return;
  vis[x]=true;
  for(auto y : v[x]){
    if(vis[y]) continue;
    dfs(y,v,vis);
  }
}

bool isConnected(vector<ll> v[],ll n){
  bool vis[n];
  for(ll i=0;i<n;i++) vis[i]=false;
  dfs(0,v,vis);
  for(ll i=0;i<n;i++){
    if(vis[i]==false) return false;
  }
  return true;
}
void edgeSubsets(ll i,ll freq[],ll n,vector<ll> curr[],ll currSum){
  if(i>=n*n){   // Subset formed
      for(int i=0;i<n;i++){
        if(freq[i]<2) return;
      }
      if(isConnected(curr,n)){
        if(ans>currSum){
          ll ct=0;
          ans=currSum;
          // cout<<currSum<<nl
          edgeAns.clear();
          for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
              if(currAdj[i][j]){
                ct++;
                if(i<=j) edgeAns.pb({i,j});
                else edgeAns.pb({j,i});
              }
            }
          }
          emin=ct;
        }
        if(ans==currSum){
          ll ct=0;
            for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
              if(currAdj[i][j]){
               ct++;
              }
            }
          }
          if(ct<emin){
            emin=ct;
             edgeAns.clear();
               for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
              if(currAdj[i][j]){
                
                if(i<=j) edgeAns.pb({i,j});
                else edgeAns.pb({j,i});
              }
            }
          }
          }
        }
      }
      return;
  }
  ll r=(i/n);
  ll c=(i%n);
  if(adj[r][c]!=INT_MAX){
  curr[r].pb(c); freq[r]++;
  curr[c].pb(r);  freq[c]++;
  currSum+=adj[r][c]; currAdj[r][c]=true;
  edgeSubsets(i+1,freq,n,curr,currSum);
  curr[r].pop_back(); freq[r]--;
  curr[c].pop_back(); freq[c]--;
  currSum-=adj[r][c]; currAdj[r][c]=false;
  edgeSubsets(i+1,freq,n,curr,currSum);
  }
  else{
  edgeSubsets(i+1,freq,n,curr,currSum);
  }
}
void solve(){
ans=INT_MAX;
    ll n,e;cin>>n>>e;
    memset(currAdj,false,sizeof(currAdj));
    for(int i=0;i<=n;i++){
      for(int j=0;j<=n;j++){
        adj[i][j]=INT_MAX;
      }
    }
    for(ll i=0;i<e;i++){
      ll u,v;cin>>u>>v;
      ll w;cin>>w;
      adj[u][v]=w;
    }
    ll freq[n];
    for(ll i=0;i<n;i++) freq[i]=0;
    vector<ll> v[n];
    edgeSubsets(0,freq,n,v,0);
    if(ans==INT_MAX) cout<<"NIL\n";
    else{
    cout<<ans<<nl;
    sort(edgeAns.begin(),edgeAns.end());
    for(auto x :edgeAns){
      cout<<x.first<<" "<<x.second<<nl;
    }
    }
}
int main()
{
  send help
  #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
  #endif
  ll t;cin>>t;
  while(t--){
  edgeAns.clear();
    solve();
  }
}
