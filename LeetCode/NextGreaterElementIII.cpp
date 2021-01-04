// Good Question
// Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.

// Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.

 

// Example 1:

// Input: n = 12
// Output: 21
// Example 2:

// Input: n = 21
// Output: -1
 

// Constraints:

// 1 <= n <= 231 - 1

// First go from back of the number to find the first element that makes the sequential order decreasing. Than swap that number with the just greater than it in the right. Than sort the numbers after the number that was selected first.
class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> v;
        int tp=n;
        while(tp>0)
        {
            v.push_back(tp%10);
            tp=tp/10;
        }
        reverse(v.begin(),v.end());
        int sz=v.size();
        int f=0;
        int l,r;
        for(int i=sz-2;i>=0;i--)
        {
            if(v[i]<v[i+1])
            {
                f=1;
                l=i;
                break;
            }
            
        }
        if(f==0)
            return -1;
        int mn=INT_MAX;
        for(int i=sz-1;i>=l+1;i--)
        {
            if(v[i]>v[l])
                mn=min(v[i],mn);
        }
        for(int i=sz-1;i>l;i--)
        {
            if(v[i]==mn) 
            {
                r=i;
                break;
            }
        }
        swap(v[l],v[r]);
        cout<<l<<" "<<r<<endl;
        int i=0;
        auto it=v.begin();
        for(;it!=v.end();it++)
        {
            if(i==l+1)
                 break;
            i++;
        }
        sort(it,v.end());
        int mx=INT_MAX;
        long long sum=0;
        long long int mul=1;
        for(int i=sz-1;i>=0;i--)
        {
            sum+=v[i]*mul;
            mul=mul*10;
            if(sum>mx)
                 return -1;
        }
        int ans=sum;
        return ans;
        
    }
};