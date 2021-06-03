// Given an m x n board of characters and a list of strings words, return all words on the board.

// Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

// Example 1:


// Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
// Output: ["eat","oath"]
// Example 2:


// Input: board = [["a","b"],["c","d"]], words = ["abcb"]
// Output: []
 

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 12
// board[i][j] is a lowercase English letter.
// 1 <= words.length <= 3 * 104
// 1 <= words[i].length <= 10
// words[i] consists of lowercase English letters.
// All the strings of words are unique.


class Solution {
public:
    set<string> ans;
    struct Node{
        char ch='&';
        Node *pt[26]={NULL};
        bool isEnd=false;
    };
    Node* root;
    int m,n;
    bool check(int i,int j){ return (i>=0 && j>=0 && i<m && j<n);}
    int dx[4]={0,-1,0,1};
    int dy[4]={-1,0,1,0};
    void dfs(vector<vector<char> > &b,Node *temp,string curr,int i,int j){
        if(temp->isEnd==true){
            ans.insert(curr);
        }
        for(int k=0;k<4;k++){
            int x=i+dx[k],y=j+dy[k];
            if(check(x,y) && b[x][y]!='$' && temp->pt[b[x][y]-'a']!=NULL ){
                char tp=b[x][y];
                b[x][y]='$';
                dfs(b,temp->pt[tp-'a'],curr+tp,x,y);
                b[x][y]=tp;
            }
        }
    }
    vector<string> findWords(vector<vector<char>>& b, vector<string>& w) {
        m=b.size(),n=b[0].size();
        root=new Node(); // making a Trie of all words in dictionary
        for(int i=0;i<w.size();i++){
            Node *temp=root;
            for(int j=0;j<w[i].length();j++){
                if(temp->pt[w[i][j]-'a']==NULL){
                    Node *tp = new Node();
                    tp->ch=w[i][j]-'a';
                    temp->pt[w[i][j]-'a']=tp;
                    temp=tp;
                }
                else{
                    temp=temp->pt[w[i][j]-'a'];
                }
            }
            temp->isEnd=true;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(root->pt[b[i][j]-'a']!=NULL){
                char tp=b[i][j];
                b[i][j]='$';
                string curr="";
                curr+=tp;
                dfs(b,root->pt[tp-'a'],curr,i,j);
                b[i][j]=tp;
                }
            }
        }
        vector<string> res;
        for(auto x : ans) res.push_back(x);
        return res;
    }
};