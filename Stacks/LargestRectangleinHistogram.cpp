// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

 


// Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

 


// The largest rectangle is shown in the shaded area, which has area = 10 unit.

 

// Example:

// Input: [2,1,5,6,2,3]
// Output: 10
 

// Example 1:


// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.
// Example 2:


// Input: heights = [2,4]
// Output: 4
 

// Constraints:

// 1 <= heights.length <= 105
// 0 <= heights[i] <= 104
#define mp make_pair
class Solution {
public:
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
};