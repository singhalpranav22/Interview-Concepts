// Find the largest continuous sequence in a array which sums to zero.

// Example:


// Input:  {1 ,2 ,-2 ,4 ,-4}
// Output: {2 ,-2 ,4 ,-4}

#define ll long long
vector<int> Solution::lszero(vector<int> &a) {
    int n=a.size();
    int sum[n+2]={0};
    sum[0]=a[0];
    int l=-1,r=-1;
    for(int i=1;i<n;i++) sum[i]=sum[i-1]+a[i];
    map<ll,pair<int,int> > m;
    int mx=-1;
    m[0].first=1;
    m[0].second=-1;
    for(int i=0;i<n;i++)
    {
        if(m[sum[i]].first == 1)
        {
            if(i-m[sum[i]].second + 1 > mx)
              {
                  l=m[sum[i]].second+1;
                  r=i;
                  mx=i-m[sum[i]].second + 1 ;
              }
             
        }
         else
              {
                  m[sum[i]].first=1;
                  m[sum[i]].second=i;
                  
              }
    }
     vector<int> ans;
     if(l==-1 || r==-1) return ans;
     for(int i=l;i<=r;i++)
       ans.push_back(a[i]);
      return ans;
       
     
}


