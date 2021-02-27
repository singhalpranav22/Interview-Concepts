// Given a set of digits (A) in sorted order, find how many numbers of length B are possible whose value is less than number C.

//  NOTE: All numbers can only have digits from the given set. 
// Examples:

// 	Input:
// 	  0 1 5  
// 	  1  
// 	  2  
// 	Output:  
// 	  2 (0 and 1 are possible)  

// 	Input:
// 	  0 1 2 5  
// 	  2  
// 	  21  
// 	Output:
// 	  5 (10, 11, 12, 15, 20 are possible)
// Constraints:

//     1 <= B <= 9, 0 <= C <= 1e9 & 0 <= A[i] <= 9

int ans=0;
void find(vector<int> A,bool hash[],int f,int i,int n,int sum)
{
    // cout<<i<<" "<<f<<" "<<" "<<sum<<nl;
    if(i==n)
     {
        //  cout<<sum<<nl;
         ans+=sum;
         return;
     }
    if(f==0)
    {
        if(i==0){
            int ct=0;
            for(int i=1;i<A[0];i++)
              {
                  if(hash[i]) ct++;
              }
              if(n==1)
              {
                  if(hash[0] && A[0]!=0) ct++;
              }
              find(A,hash,1,i+1,n,ct);
              if(hash[A[0]] && i!=n-1)
              find(A,hash,0,i+1,n,1);
        }
        else{
            int ct=0;
            for(int j=0;j<A[i];j++)
              {
                  if(hash[j]) ct++;
              }
              find(A,hash,1,i+1,n,sum*ct);
              if(hash[A[i]] && i!=n-1){
                
              find(A,hash,0,i+1,n,sum*1);
              }
        }
    }
    else
       {
            int ct=0;
            for(int j=0;j<=9;j++)
              {
                  if(hash[j]) ct++;
              }
           
              find(A,hash,1,i+1,n,sum*ct);
       }
}
int Solution::solve(vector<int> &A, int B, int C) {
    bool hash[10];
    memset(hash,false,sizeof(hash));
    for(auto x: A) hash[x]=true;
    // for(auto x : hash) cout<<x<<" ";
    // cout<<nl;
    vector<int> digits;
    int temp=C;
    while(temp>0)
    {
        digits.push_back(temp%10);
        temp/=10;
    }
    reverse(digits.begin(),digits.end());
    if(B>digits.size()) return 0;
    if(B==digits.size()){
        ans=0;
        // for(auto x: digits) cout<<x<<" ";
        // cout<<nl;
        find(digits,hash,0,0,digits.size(),0);
        return ans;
    }
    if(B<digits.size()){
        int ct=0;
            for(int j=0;j<=9;j++)
              {
                  if(hash[j]) ct++;
              }
        ans=0;
        for(int i=1;i<=B;i++)
        {
            if(i==1)
            {
                if(hash[0]==1 && B!=1)
                {
                    ans=ct-1;
                }
                else
                 ans=ct;
                 
                 continue;
            }
            ans=ans*ct;
        }
        return ans;
    }
}