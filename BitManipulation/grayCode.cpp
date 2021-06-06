// The gray code is a binary numeral system where two successive values differ in only one bit.

// Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

// For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

// 00 - 0
// 01 - 1
// 11 - 3
// 10 - 2
// There might be multiple gray code sequences possible for a given n.
// Return any such sequence.

// XOR sol
vector<int> Solution::grayCode(int A) {
     vector<int> ans;
     for(int i=0;i<(1<<A);i++) ans.push_back(i^(i>>1));
     return ans;
}

// backtracking
vector<string> find(int n){
    if(n==1){
        vector<string> ans = {"0","1"};
        return ans;
    }
    vector<string> temp = find(n-1);
    vector<string> ans;
    for(int i=0;i<temp.size();i++){
        ans.push_back("0"+temp[i]);
    }
     for(int i=temp.size()-1;i>=0;i--){
        ans.push_back("1"+temp[i]);
    }
    return ans;
}
int solve(string s){
    int mul=1;
    int ans=0;
    for(int i=s.length()-1;i>=0;i--){
        ans+=mul*(s[i]-'0');mul*=2;
    }
    return ans;
}
vector<int> Solution::grayCode(int A) {
     vector<int> ans;
     vector<string> temp=find(A);
     for(auto x : temp){ans.push_back(solve(x));}
     return ans;
    
}
