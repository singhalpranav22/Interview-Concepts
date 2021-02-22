// Given two words A and B, and a dictionary, C, find the length of shortest transformation sequence from A to B, such that:

// You must change exactly one character in every transformation.
// Each intermediate word must exist in the dictionary.
// Note:

// Return 0 if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.


// Input Format:

// The first argument of input contains a string, A.
// The second argument of input contains a string, B.
// The third argument of input contains an array of strings, C.
// Output Format:

// Return an integer representing the minimum number of steps required to change string A to string B.
// Constraints:

// 1 <= length(A), length(B), length(C[i]) <= 25
// 1 <= length(C) <= 5e3
// Example :

// Input 1:
//     A = "hit"
//     B = "cog"
//     C = ["hot", "dot", "dog", "lot", "log"]

// Output 1:
//     5

// Explanation 1:
//     "hit" -> "hot" -> "dot" -> "dog" -> "cog"

// Make Graph & use BFS to find minimum distance between two nodes.

#define pb push_back
 bool vis[50005];
 int dist[50005];
int Solution::solve(string A, string B, vector<string> &C) {
    vector<int> g[C.size()+2];
    vector<string> v;
    v.pb(A);
    for(int i=0;i<C.size();i++) v.pb(C[i]);
    v.pb(B);
    int n=v.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j) continue;
            bool f=false;
            bool ok=true;
            for(int k=0;k<v[j].length();k++)
            {
                if(v[i][k]!=v[j][k])
                {
                    if(f==true){
                        ok=false;
                        break;
                    } 
                    f=true;
                }
            }
            if(ok) g[i].pb(j);
        }
    }
    queue<int> q;
    q.push(0);
    memset(vis,false,sizeof(vis));
    vis[0]=true;
    memset(dist,0,sizeof(dist));
    dist[0]=1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(auto y : g[x])
        {
            if(vis[y]==false)
            {
                dist[y]=dist[x]+1;
                vis[y]=true;
                q.push(y);
            }
        }
    }
    if(vis[n-1]) return dist[n-1];
    else return 0;
}
