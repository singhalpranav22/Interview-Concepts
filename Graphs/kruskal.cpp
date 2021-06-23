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
//     We can choose bridges (1, 2, 1), (2, 3, 2) and (1, 4, 3), where the total cost incurred will be (1 + 2 + 3) = 6.


Kruskal’s Algorithm builds the spanning tree by adding edges one by one into a growing spanning tree. Kruskal's algorithm follows greedy approach as in each iteration it finds an edge which has least weight and add it to the growing spanning tree.

Algorithm Steps:

Sort the graph edges with respect to their weights.
Start adding edges to the MST from the edge with the smallest weight until the edge of the largest weight.
Only add edges which doesn't form a cycle , edges which connect only disconnected components.
So now the question is how to check if  vertices are connected or not ?

This could be done using DFS which starts from the first vertex, then check if the second vertex is visited or not. But DFS will make time complexity large as it has an order of  where  is the number of vertices,  is the number of edges. So the best solution is "Disjoint Sets":
Disjoint sets are sets whose intersection is the empty set so it means that they don't have any element in common.



// DSU for kruskal
int par[100005];
int findPar(int x){
    if(par[x]==x) return x;
    x=par[x];
    return findPar(x);
}
void un(int a,int b){
    int parA=findPar(a),parB=findPar(b);
    par[parA]=parB;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    for(int i=0;i<=A;i++) par[i]=i;
    int ans=0;
    vector<pair<int,pair<int,int> > > edges;
    for(int i=0;i<B.size();i++){
        edges.push_back({B[i][2],{B[i][0],B[i][1]}});
    }
    sort(edges.begin(),edges.end());
    for(auto x : edges){
        if(findPar(x.second.first)==findPar(x.second.second)) continue;
        ans+=x.first;
        un(x.second.first,x.second.second);
    }
    return ans;
}
