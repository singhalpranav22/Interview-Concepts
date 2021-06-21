// Floyd warshall

Floyd\u2013Warshall's Algorithm is used to find the shortest paths between between all pairs of vertices in a graph, where each edge in the graph has a weight which is positive or negative. The biggest advantage of using this algorithm is that all the shortest distances between any  vertices could be calculated in , where  is the number of vertices in a graph.

The Algorithm Steps:

For a graph with  vertices:

Initialize the shortest paths between any  vertices with Infinity.
Find all pair shortest paths that use  intermediate vertices, then find the shortest paths that use  intermediate vertex and so on.. until using all  vertices as intermediate nodes.
Minimize the shortest paths between any  pairs in the previous operation.
For any  vertices  , one should actually minimize the distances between this pair using the first  nodes, so the shortest path will be: .
 represents the shortest path that only uses the first  vertices,  represents the shortest path between the pair . As the shortest path will be a concatenation of the shortest path from  to , then from  to .

for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dist[i][j] = min( dist[i][j], dist[i][k] + dist[k][j] );
        }
    }
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
 int dist[n+1][n+1];
 for(int i=1;i<=n;i++){
	 for(int j=1;j<=n;j++) {
		 if(i==j) dist[i][j]=0;
		 dist[i][j]=1e09;}
 }
 for(int i=1;i<=m;i++){
	 int f,t,w;cin>>f>>t>>w;
	 dist[f][t]=w; // fill for those first who are reachable from f->t with weight w
 }
 for(int k=1;k<=n;k++){
	 for(int i=1;i<=n;i++){
		 for(int j=1;j<=n;j++){
			 dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
		 }
	 }
 }
  for(int i=2;i<=n;i++) cout<<dist[1][i]<<" ";
 
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