int Solution::solve(vector<int> &A) {

int N = A.size() ;

int t[N][N];
memset( t , 0 , sizeof t);

int p[N+1]; p[0] = 0  ;
for( int i = 0 ; i < N ; i++ )p[i+1] = p[i] + A[i];

for( int L = 2 ; L <= N ; L++ )
for( int i = 0 ; i+L-1<N; i++ )
{
    int j = i+L-1;
    t[i][j] = INT_MAX ; 
    
    for( int k = i ; k <= j ; k++ )
    t[i][j] = min( t[i][j] , t[i][k] + t[k+1][j] + p[j+1]-p[i] );
}
return t[0][N-1];
}