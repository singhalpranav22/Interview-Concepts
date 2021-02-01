 vector<int> adj[1000007];
 int vis[10000007];
void dfs(int x,int A,int &ans)
{
    if(x==A)
         ans=1;
    if(vis[x]!=1)
    {
        vis[x]=1;
        for(auto y : adj[x])
        {
           
            if(vis[y]!=1)
            {
                 
                dfs(y,A,ans);
            }
        }
    }
}
int Solution::solve(int A, vector<vector<int> > &B) {
   
    for(int i=1;i<=200000;i++) adj[i].clear();
    memset(vis,0,sizeof(vis));
    if(B.size()==0) return 0;
    for(int i=0;i<B.size();i++)
    {
        adj[B[i][0]].push_back(B[i][1]);
    }
    int ans=0;
    dfs(1,A,ans);
    return ans;
    
}
