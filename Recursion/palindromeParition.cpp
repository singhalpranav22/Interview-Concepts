// 131. Palindrome Partitioning
// Medium

// 3466

// 112

// Add to List

// Share
// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

// A palindrome string is a string that reads the same backward as forward.

 

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]
 

// Constraints:

// 1 <= s.length <= 16
// s contains only lowercase English letters.

// Used dp[i][j] to tell whether string between i and j is a palindrome or not.
// Can be solve with naive isPalin function as well.

class Solution {
public:
    bool dp[20][20];
    vector<vector<string> > ans;
    bool isPalin(string s){
        int l=0,r=s.length()-1;
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++,r--;
        }
        return true;
    }
    void find(int st,int i,string curr,string s,vector<string> v,int n){
       if(i==n){
           if(dp[st][n-1]){
               v.push_back(curr);
               ans.push_back(v);
           }
           return;
       }
        if(dp[st][i-1]){
            string temp=curr;
            temp+=s[i];
            find(st,i+1,temp,s,v,n);
            v.push_back(curr);
            curr="";
            curr+=s[i];
            find(i,i+1,curr,s,v,n);
        }
        else
        {
            curr+=s[i];
            find(st,i+1,curr,s,v,n);
        }
    }
    vector<vector<string>> partition(string s) {
        memset(dp,false,sizeof(dp));
        int n=s.length();
        for(int i=0;i<n;i++) dp[i][i]=true;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]) dp[i][i+1]=true;
            else dp[i][i+1]=false;
        }
        int gap=2;
        while(gap<n){
            int i=0;
            while(i+gap<n){
                if(s[i]==s[i+gap]){
                    dp[i][i+gap]=dp[i+1][i+gap-1];
                }
                i++;
            }
            gap++;
        }
        string a;
        a+=s[0];
        vector<string> v;
        find(0,1,a,s,v,s.length());
        return ans;
        
    }
};