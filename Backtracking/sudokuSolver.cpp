// Write a program to solve a Sudoku puzzle by filling the empty cells.
// Empty cells are indicated by the character '.'
// You may assume that there will be only one unique solution.



// A sudoku puzzle,



// and its solution numbers marked in red.

// Example :

// For the above given diagrams, the corresponding input to your program will be

// [[53..7....], [6..195...], [.98....6.], [8...6...3], [4..8.3..1], [7...2...6], [.6....28.], [...419..5], [....8..79]]
// and we would expect your program to modify the above array of array of characters to

// [[534678912], [672195348], [198342567], [859761423], [426853791], [713924856], [961537284],

vector<vector<char> > ans;
bool check(vector<vector<char> > &v,int i,int j,int x)
{
    for(int k=0;k<9;k++)
    {
        if(k==j) continue;
        if(v[i][k]==(x+'0')) return false;
    }
    for(int k=0;k<9;k++){
        if(k==i) continue;
        if(v[k][j]==(x+'0')) return false;
    }
    int it=3*floor(i/3);
    int jt=3*floor(j/3);
    for(int p=it;p<it+3;p++)
    {
        for(int q=jt;q<jt+3;q++)
        {
            if(p==i && q==j) continue;
            if(v[p][q]==(x+'0')) return false;
        }
    }
    return true;
}
void find(vector<vector<char> > &v,int it)
{
    if(it>80)
    {
        ans=v;
        return;
    }
    int i=it/9;
    int j=it-(9*i);
    if(v[i][j]!='.') {find(v,it+1);return;}
    for(int p=1;p<=9;p++){
        if(check(v,i,j,p)){
            v[i][j]=p+'0';
            find(v,it+1);
            v[i][j]='.';
        }
    }
    return;
}
void Solution::solveSudoku(vector<vector<char> > &A) {
    ans.clear();
    find(A,0);
    A=ans;
}