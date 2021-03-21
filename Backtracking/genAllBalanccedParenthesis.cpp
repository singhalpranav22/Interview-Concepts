// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.

// For example, given n = 3, a solution set is:

// "((()))", "(()())", "(())()", "()(())", "()()()"
// Make sure the returned list of strings are sorted.

vector<string> ans;

void find(stack<char> s,string curr,int n){
    if(n==0 && s.size()==0){
        ans.push_back(curr);
        return;
    }
    if(n>0){
        curr+='(';
        s.push('(');
        find(s,curr,n-1);
         curr.pop_back();
         s.pop();
    }
   if(s.size()>0){
        curr+=')';
        s.pop();
        find(s,curr,n);
    }
    return;
}


vector<string> Solution::generateParenthesis(int A) {
    ans.clear();
    stack<char> s;
    find(s,"",A);
    return ans;
}
