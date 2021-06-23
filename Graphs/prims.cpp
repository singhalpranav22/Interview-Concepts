// There are A islands and there are M bridges connecting them. Each bridge has some cost attached to it.

// We need to find bridges with minimal cost such that all islands are connected.

// It is guaranteed that input data will contain at least one possible scenario in which all islands are connected with each other.

// Input Format:

// The first argument contains an integer, A, representing the number of islands.
// The second argument contains an 2-d integer matrix, B, of size M x 3:
//     => Island B[i][0] and B[i][1] are connected using a bridge of cost B[i][2].
// Output Format:

// Return an integer representing the minimal cost required.
// Constraints:

// 1 <= A, M <= 6e4
// 1 <= B[i][0], B[i][1] <= A
// 1 <= B[i][2] <= 1e3
// Examples:

// Input 1:
//     A = 4
//     B = [   [1, 2, 1]
//             [2, 3, 4]
//             [1, 4, 3]
//             [4, 3, 2]
//             [1, 3, 10]  ]

// Output 1:
//     6

// Explanation 1:
//     We can choose bridges (1, 2, 1), (1, 4, 3) and (4, 3, 2), where the total cost incurred will be (1 + 3 + 2) = 6.

// Input 2:
//     A = 4
//     B = [   [1, 2, 1]
//             [2, 3, 2]
//             [3, 4, 4]
//             [1, 4, 3]   ]

// Output 2:
//     6

// Explanation 2:
//     We can choose bridges (1, 2, 1), (2, 3, 2) and (1, 4, 3), where the total cost incurred

Prim’s Algorithm
Prim’s Algorithm also use Greedy approach to find the minimum spanning tree. In Prim’s Algorithm we grow the spanning tree from a starting position. Unlike an edge in Kruskal's, we add vertex to the growing spanning tree in Prim's.

Algorithm Steps:

Maintain two disjoint sets of vertices. One containing vertices that are in the growing spanning tree and other that are not in the growing spanning tree.
Select the cheapest vertex that is connected to the growing spanning tree and is not in the growing spanning tree and add it into the growing spanning tree. This can be done using Priority Queues. Insert the vertices, that are connected to growing spanning tree, into the Priority Queue.
Check for cycles. To do that, mark the nodes which have been already selected and insert only those nodes in the Priority Queue that are not marked.

vector<pair<int,int> > adj[100001];
int Solution::solve(int A, vector<vector<int> > &B) {
    for(int i=0;i<=A;i++) adj[i].clear();
    int ans=0;
    for(int i=0;i<B.size();i++){
        adj[B[i][0]].push_back({B[i][1],B[i][2]});
        adj[B[i][1]].push_back({B[i][0],B[i][2]});
    }
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    // Prim's Algorithm
    bool vis[A+1];
    memset(vis,false,sizeof(vis));
    q.push({0,1}); /// pushing node 1 (arbitarary selecting the first node for the MST)
    while(!q.empty()){
        int weight = q.top().first;
        int node = q.top().second;
        q.pop();
        if(vis[node])continue;
        ans+=weight;
        vis[node]=true;
        for(auto x : adj[node]){
            if(vis[x.first]) continue;
            q.push({x.second,x.first});
        }
    }
    return ans;
}
