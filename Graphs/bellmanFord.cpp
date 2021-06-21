// Bellman Ford's Algorithm:
// Bellman Ford's algorithm is used to find the shortest paths from the source vertex to all other vertices in a weighted graph. It depends on the following concept: Shortest path contains at most  edges, because the shortest path couldn't have a cycle.

// So why shortest path shouldn't have a cycle ?
// There is no need to pass a vertex again, because the shortest path to all other vertices could be found without the need for a second visit for any vertices.

// Algorithm Steps:

// The outer loop traverses from  : .
// Loop over all edges, check if the next node distance > current node distance + edge weight, in this case update the next node distance to "current node distance + edge weight".
// This algorithm depends on the relaxation principle where the shortest distance for all vertices is gradually replaced by more accurate values until eventually reaching the optimum solution. In the beginning all vertices have a distance of "Infinity", but only the distance of the source vertex = , then update all the connected vertices with the new distances (source vertex distance + edge weights), then apply the same concept for the new vertices with new distances and so on.

// You are given 2 integers , N is the number of vertices, M is the number of edges. You'll also be given  , ,  where  and  represents an edge from a vertex  to a vertex  and  respresents the weight of that edge.

// Task is to find the shortest path from source vertex (vertex number 1) to all other vertices () where ().

// Input:

// First line contains two space separated integers,  Then M lines follow, each line has 3 space separated integers  , , .

// Output:
// Print the shortest distances from the source vertex (vertex number 1) to all other vertices () where (). Print "" in case the vertex "" can't be reached form the source vertex.
// Leave a space between any 2 printed numbers



// SAMPLE INPUT 
// 5 5
// 1 2 5
// 1 3 2
// 3 4 1
// 1 4 6
// 3 5 5
// SAMPLE OUTPUT 
// 5 2 3 7

t-> O(V.E)
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
  vector<pair<int,pair<int,int> > > v; // stores the edges as {weight , {i->j}} as we have to traverse on the edges in the Bellman Ford shortest distance algorithm
  for(int i=1;i<=m;i++){
	  int from,to,weight;cin>>from>>to>>weight;
	  v.push_back({weight,{from,to}});
  }
  for(int i=1;i<n;i++){ // first loop traverses n-1 times in Bellman ford
	for(auto x : v){ // traverse all the edges
		int from = x.second.first;
		int to=x.second.second;
		int weight=x.first;
		if(dist[to]>dist[from]+weight) dist[to]=dist[from]+weight;
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