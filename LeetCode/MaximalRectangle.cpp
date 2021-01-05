// https://leetcode.com/problems/maximal-rectangle/
// Just an extension of Maximum area rectangle in a histogram. We construct towers at every level & than find the max area. Than take the best result as answer.
// Basically, We have transformed the 2-D matrix to 1-D vector level wise, ans than use the histogram max rect function to find answer for that level, than we return the max ans of all the levels.
#define mp make_pair
class Solution {
public:
    // code of largest Area in histogram
    int largestRectangleArea(vector<int>& h) {
        stack<pair<int,int> >st;
        int n=h.size();
        vector<int> nsr(n),nsl(n);
        // Find the first bar on the right side of the current bar
        // which is smaller than its value
        for(int i=n-1;i>=0;i--)
        {
            if(st.size()==0)
            {
                nsr[i]=n-1;
                st.push(mp(h[i],i));
                continue;
            }
            else if(st.top().first<h[i])
            {
                nsr[i]=st.top().second-1;
            }
            else
            {
                while(st.top().first>h[i])
                {
                    st.pop();
                    if(st.size()==0) break;
                }
                if(st.size()==0)
                {
                    nsr[i]=n-1;
                    st.push(mp(h[i],i));
                    continue;
                }
                else{
                    if(st.top().first!=h[i])
                        nsr[i]=st.top().second-1;
                    else
                    {
                        nsr[i]=nsr[st.top().second];
                        st.pop();
                        
                    }
                }
            }
            st.push(mp(h[i],i));
        }
        
        while(st.size()>0) st.pop();
        
        // Find the first bar on the left side of the current bar
        // which is smaller than its value
        for(int i=0;i<n;i++)
        {
            if(st.size()==0)
            {
                nsl[i]=0;
                st.push(mp(h[i],i));
                continue;
            }
            else if(st.top().first<h[i])
            {
                nsl[i]=st.top().second+1;
            }
            else
            {
                while(st.top().first>h[i])
                {
                    st.pop();
                    if(st.size()==0) break;
                }
                if(st.size()==0)
                {
                    nsl[i]=0;
                    st.push(mp(h[i],i));
                    continue;
                }
                else{
                    if(st.top().first!=h[i])
                        nsl[i]=st.top().second+1;
                    else
                    {
                        nsl[i]=nsl[st.top().second];
                        st.pop();
                       
                    }
                }
            }
            st.push(mp(h[i],i));
        }
        int ans=0;
        // Compute maximum area that can be obtained by
        // including the bar
        for(int i=0;i<n;i++)
        {
            int temp=h[i]*1 + (nsr[i]-i)*h[i] + (i-nsl[i])*h[i];
            ans=max(ans,temp);
        }
        return ans;
        
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        int n=mat.size();
        if(n==0) return 0;
        int m=mat[0].size();
        if( m==0) return 0;
        int ans=0;
        int dp[n][m]; // for optimizing the finding of height of a level based on the previous level
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            vector<int> h(m);
            for(int j=0;j<m;j++)
            {
                int height=0;
                if(i==0) // base case
                {
                    if(mat[i][j]=='0')
                        height=0;
                    else{
                         height=1;
                        dp[i][j]=1;}
                }
                else{
                    if(mat[i][j]=='0') height=0;
                    else{
                        height=dp[i-1][j]+1;
                        dp[i][j]=height;
                    }
                }
                h[j]=height;
            }
            // for(auto x:h) cout<<x<<" ";
            // cout<<endl;
            int temp=largestRectangleArea(h);
            ans=max(ans,temp);
            
        }
        return ans;
            
    }
};