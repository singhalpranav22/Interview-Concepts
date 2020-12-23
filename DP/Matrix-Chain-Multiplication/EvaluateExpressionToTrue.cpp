// Given an expression, A, with operands and operators (OR , AND , XOR), in how many ways can you evaluate the expression to true, by grouping in different ways?

// Operands are only true and false.

// Return the number of ways to evaluate the expression modulo 103 + 3.



// Input Format:

// The first and the only argument of input will contain a string, A.

// The string A, may contain these characters:
//     '|' will represent or operator 
//     '&' will represent and operator
//     '^' will represent xor operator
//     'T' will represent true operand
//     'F' will false
// Output:

// Return an integer, representing the number of ways to evaluate the string.
// Constraints:

// 1 <= length(A) <= 150
// Example:

// Input 1:
//     A = "T|F"

// Output 1:
//     1

// Explanation 1:
//     The only way to evaluate the expression is:
//         => (T|F) = T 

// Input 2:
//     A = "T^T^F"
    
// Output 2:
//     0
    
// Explanation 2:
//     There is no way to evaluate A to a true statement.


#define mod 1003
int dp[155][155][2];
int find(string s,int i,int j,bool b)
{
    if(i>j) return 0;
    if(i==j)
    {
        if(b==true)
          return s[i]=='T';
         else if(b==false)
          return s[i]=='F';
    }
    int ans=0;
    for(int k=i+1;k<j;k+=2)
    {
        
        int tmp;
        int lft,rgt,lff,rgf;
        if(dp[i][k-1][1]!=-1) // Finding number of trues in the left of 'k'
         lft=dp[i][k-1][1];
        else
        {
            lft=find(s,i,k-1,true)%mod;
            dp[i][k-1][1]=lft;
        }
        if(dp[k+1][j][1]!=-1) // Finding number of trues in the right of 'k'
         rgt=dp[k+1][j][1];
        else
        {
            rgt=find(s,k+1,j,true)%mod;
            dp[k+1][j][1]=rgt;
        }
        if(dp[i][k-1][0]!=-1) // Finding number of false in the left of 'k'
         lff=dp[i][k-1][0];
        else
        {
            lff=find(s,i,k-1,false)%mod;
            dp[i][k-1][0]=lff;
        }
        if(dp[k+1][j][0]!=-1) // Finding number of false in the right of 'k'
         rgf=dp[k+1][j][0]; 
        else
        {
            rgf=find(s,k+1,j,false)%mod;
            dp[k+1][j][0]=rgf;
        }
        if(s[k]=='^') //cases for XOR
         {
             if(b==true) 
             {
                tmp= ((lff*rgt)%mod+(lft*rgf)%mod)%mod; 
             }
             else{
                 tmp= ((lff*rgf)%mod+(lft*rgt)%mod)%mod;
             }
         }
        else if(s[k]=='|') //cases for OR
        {
            if(b==true)
            {
                tmp= ((lft*rgt)%mod+(lff*rgt)%mod+(lft*rgf)%mod)%mod;
            }
            else{
                tmp= (lff*rgf)%mod;
            }
        }
        else if(s[k]=='&'){
            if(b==true){
                tmp= (lft*rgt)%mod;
            }
            else{
                tmp= ((lff*rgf)%mod+(lft*rgf)%mod+(lff*rgt)%mod)%mod;
            }
        }
        ans=(ans+tmp)%mod;
    }
    return ans%mod;
}
int Solution::cnttrue(string A) {
    memset(dp,-1,sizeof(dp));
    if(A.length()==0) return 0;
    return find(A,0,A.length()-1,true);
    
}
