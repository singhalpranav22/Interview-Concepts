// Shortest distance from single source to all nodes in
// to implementations one brute force, other using priotiy queue(min heap)
// You are given 2 integers , N is the number of vertices, M is the number of edges. You'll also be given  , ,  where  and  represents an edge from a vertex  to a vertex  and  respresents the weight of that edge.

// Task is to find the shortest path from source vertex (vertex number 1) to all other vertices () where ().

// Input:

// First line contains two space separated integers,  Then M lines follow, each line has 3 space separated integers  , , .

// Output:
// Print the shortest distances from the source vertex (vertex number 1) to all other vertices () where (). Print "" in case the vertex "" can't be reached form the source vertex.
// Leave a space between any 2 printed numbers.

// Constraints:
// 1<=N<=10^4
// 1<=M<=10^6
// 1<=w<=1000


// SAMPLE INPUT 
// 5 5
// 1 2 5
// 1 3 2
// 3 4 1
// 1 4 6
// 3 5 5
// SAMPLE OUTPUT 
// 5 2 3 7

// Brute force djisktra
// using priority queue is good for sparse graphs, in case of dense graphs there is an overhead of O(n^2logn)
// PRANAV SINGHAL
// IIIT-Allahabad
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
#define ALL(v) (v.begin(), v.end())
void solve(){
 ll n,m;cin>>n>>m;
  int dist[n+1];
  dist[1]=0; // source node
   for(int i=2;i<=n;i++) {
	  dist[i]=1e09;  // initialise initial distances as inf
	  }
  vector<pair<int,int> > v[n+1];
  for(int i=1;i<=m;i++){
	  int from,to,weight;cin>>from>>to>>weight;
	  v[from].push_back({to,weight});
  }
  bool vis[n+1];
  memset(vis,false,sizeof(vis));
while(1){
	int mnInd=0;
	int mn=INT_MAX;
	bool f=false; // to check if all are visited
	for(int i=1;i<=n;i++){
		if(vis[i]==false) f=true;
		if(!vis[i] && dist[i]<mn) {mnInd = i;mn=dist[i];}
	}
	if(!f) break;
	vis[mnInd]=true;
	int d = dist[mnInd]; // stores the distance till node mnInd
	for(auto x : v[mnInd]){
		if(!vis[x.first] && dist[x.first]>d+x.second){
			dist[x.first]=d+x.second;
		}
	}
}
  for(int i=2;i<=n;i++) cout<<dist[i]<<" ";
 
}
int main()
{
  send help
  #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
  #endif
    solve();
   
    
  return 0;
}

// using priority queue is good for sparse graphs, in case of dense graphs there is an overhead of O(n^2logn)
// PRANAV SINGHAL
// IIIT-Allahabad
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
#define ALL(v) (v.begin(), v.end())
void solve(){
 ll n,m;cin>>n>>m;
  int dist[n+1];
  dist[1]=0; // source node
  vector<pair<int,int> > v[n+1];
  for(int i=1;i<=m;i++){
	  int from,to,weight;cin>>from>>to>>weight;
	  v[from].push_back({to,weight});
  }
   priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > d; // best ds to use better then multiset
//   map<int,int> d; // map can't work as we cannot sort it by values
//   multiset<pair<int,int> > d; // can be also used almost same as priority_queue
  for(int i=2;i<=n;i++) {
	  dist[i]=1e09;  // initialise initial distances as inf
	  }
	  d.push({0,1}); // inserting node 1
  bool vis[n+1];
  memset(vis,false,sizeof(vis));
  while(d.size()>0){
	  pair<int,int> pt = d.top();  // contains the smallest distance in top
	  int currd = pt.first;
	  int curr=pt.second;
	  d.pop();
	  if(vis[curr]==true) continue;  // if already visited before with even shorter distance no need to go further
	  vis[curr]=true; // visit it
	  for(auto x : v[curr]){. // relax neighbours
		  if(!vis[x.first]){
		  if(currd+x.second<dist[x.first]){ // if neighbour can be relaxed, relax it and push it into the queue
			  dist[x.first]=currd+x.second;
			  d.push({dist[x.first],x.first});
		  }
		  }
	  }
  }
  for(int i=2;i<=n;i++) cout<<dist[i]<<" ";
   
 
}
int main()
{
  send help
  #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
  #endif
    solve();
   
    
  return 0;
}


