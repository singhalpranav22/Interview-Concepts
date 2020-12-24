// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]
 

// Constraints:

// 1 <= n <= 8


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> ans;
    void find(string s,stack<char> st,int n)
    {
        if(st.size()==0 && n!=0)
        {
            st.push('(');
            s+="(";
            n--;
        }
        if(n==0)
        {
            for(int i=1;i<=st.size();i++) s+=")";
            ans.push_back(s);
            return ;
        }
        string a;
        a+=s;
        st.push('(');
        a+="(";
        n--;
        find(a,st,n);
        n++;
        string b;
        st.pop();
        b+=s+')';
        st.pop();
        find(b,st,n);
      
        return;
    }
    vector<string> generateParenthesis(int n) {
        stack<char> st;
        string s="";
        find(s,st,n);
        return ans;
    }
};

int main(){
    Solution ob;
    vector<string> v=ob.generateParenthesis(8);
    for(auto x :v) cout<<x<<endl;
}