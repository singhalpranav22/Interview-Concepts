void solve(vector<vector<int> > &ans,vector<int> &A,int i,int n)
{
    if(i==n){
      ans.push_back(A);return;}
     for(int j=i;j<=n;j++)
     {
         int temp=A[i];
         A[i]=A[j];
         A[j]=temp;
         solve(ans,A,j+1,n);
         temp=A[i];
         A[i]=A[j];
         A[j]=temp;
     }
}
vector<vector<int> > permute(vector<int> &A) {
    int n=A.size();
    vector<vector<int> > ans;
    ans.clear();
    solve(ans,A,0,n);
    return ans;
}