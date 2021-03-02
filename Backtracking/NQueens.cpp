// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

// N Queens: Example 1

// Given an integer n, return all distinct solutions to the n-queens puzzle.

// Each solution contains a distinct board configuration of the n-queens’ placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

// For example,
// There exist two distinct solutions to the 4-queens puzzle:

// [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],

//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]

vector<vector<string> > ans;
bool check(vector<vector<int> > v,int i,int j,int n)
{
    int it=i;
    int jt=j;
    it--;
    jt--;
    while(it>=0 && jt>=0)
    {
        if(v[it][jt]==1) return false;
        it--;
        jt--;
    }
    it=i-1;
    jt=j+1;
    while(it>=0 && jt<n){
        if(v[it][jt]==1) return false;
        it--;
        jt++;
    }
    return true;
}
void find(vector<vector<int> > v,int i,int n,int vis[])
{
    if(i==n) {
        vector<string> temp;
        for(int i=0;i<n;i++)
        {
            string s;
            for(int j=0;j<n;j++){
                if(v[i][j]==1) s+='Q';
                else s+='.';
            }
            temp.push_back(s);
        }
        ans.push_back(temp);
    }
    for(int j=0;j<n;j++)
    {
        if(vis[j]!=1)
        {
            if(check(v,i,j,n)){
                vis[j]=1;
                v[i][j]=1;
                find(v,i+1,n,vis);
                vis[j]=0;
                v[i][j]=0;
            }
        }
    }
    
}
vector<vector<string> > Solution::solveNQueens(int n) {
    ans.clear();
    vector<vector<int> > v(n,vector<int> (n));
    int vis[n];
    for(int i=0;i<n;i++) vis[i]=0;
    find(v,0,n,vis);
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
}
