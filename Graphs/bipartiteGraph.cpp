// Try to color node red and it's neighbors blue in one dfs call.

Problem Description

There are A people numbered 1 to A in a football academy.

The coach of the academy wants to make two teams (not necessary of equal size) but unfortunately, not all people get along, and several refuse to be put on the same team as that of their enemies.

Given a 2-D array B of size M x 2 denoting the enemies i.e B[i][0] and B[i][1] both are enemies of each other.

Return 1 if it possible to make exactly two teams else return 0.



Problem Constraints
2 <= A <= 105

1 <= M <= 105

1 <= B[i][0], B[i][1] <= A

B[i][0] != B[i][1]



Input Format
First argument is an integer A denoting number of peoples.

Second argument is a 2-D array B of size M x 2 denoting enemies.



Output Format
Return 1 if it possible to make exactly two teams else return 0.



Example Input
Input 1:

 A = 5
 B = [ [1, 2],
       [2, 3],
       [1, 5],
       [2, 4] ] 
Input 2:

 A = 4
 B = [ [1, 4],
       [3, 1],
       [4, 3],
       [2, 1] ]


Example Output
Output 1:

 1 
Output 2:

 0 


Example Explanation
Explanation 1:

 We can make two teams [1, 3, 4] and [2, 5].
Explanation 2:

 No possible way to create two teams. So, we need to return 0.


Note:You only need to implement the given function. Do not read input, instead use the arguments to the function. Do not print the output, instead return values as specified. Still have a doubt? Checkout Sample Codes for more details.


int vis[100005];
vector<int> adj[100005];
int c=0;
bool dfs(int curr,int f){
    c++;
    if(f==0)
    vis[curr]=1; //blue
    else 
    vis[curr]=2; //red
    for(auto x : adj[curr]){
        if(vis[x]==0){
            if(f==0)
            dfs(x,1);
            else
            dfs(x,0);
        }
        else if(vis[x]==1){
            if(f==0)
                  return false;
        }
        else if(vis[x]==2){
            if(f==1) return false;
        }
    }
    return true;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    for(int i=1;i<=A;i++) adj[i].clear();
    for(int i=0;i<B.size();i++){
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    memset(vis,false,sizeof(vis));
    bool f=false;
    c=0;
    bool ans=true;
    for(int i=1;i<=A;i++){
        c=0;
        if(!vis[i]){
            ans= ans && dfs(i,0);
           
        }
    }
    return ans;
}
