// Given a 2D board and a word, find if the word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The cell itself does not count as an adjacent cell.
// The same letter cell may be used more than once.

// Example :

// Given board =

// [
//   ["ABCE"],
//   ["SFCS"],
//   ["ADEE"]
// ]
// word = "ABCCED", -> returns 1,
// word = "SEE", -> returns 1,
// word = "ABCB", -> returns 1,
// word = "ABFSAB" -> returns 1
// word = "ABCD" -> returns 0
// Note that 1 corresponds to true, and 0 corresponds to false.

// Simple DFS search !


void dfs(vector<string> A,string s,string curr,int i,int j,int &f,int it,int sz)
{
    if(it==sz)
      {
          f=1;
          return;
      }
    if(i<A.size()-1 && A[i+1][j]==s[it])
         {
             dfs(A,s,curr+s[it],i+1,j,f,it+1,sz);
             if(f==1) return;
         }
    if(i>0 && A[i-1][j]==s[it])
    {
        dfs(A,s,curr+s[it],i-1,j,f,it+1,sz);
         if(f==1) return;
    }
    if(j>0 && A[i][j-1]==s[it])
    {
        dfs(A,s,curr+s[it],i,j-1,f,it+1,sz);
         if(f==1) return;
    }
    if(j<A[i].length()-1 && A[i][j+1]==s[it])
    {
        dfs(A,s,curr+s[it],i,j+1,f,it+1,sz);
         if(f==1) return;
    }

}
int Solution::exist(vector<string> &A, string B) {
    int f=0;
    int sz=B.length();
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[i].length();j++)
        {
            if(A[i][j]==B[0]) dfs(A,B,"",i,j,f,1,sz);
            if(f==1) break;
        }
        if(f==1) break;
    }
    return f;
}
