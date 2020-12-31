// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



 

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = ""
// Output: []
// Example 3:

// Input: digits = "2"
// Output: ["a","b","c"]
 

// Constraints:

// 0 <= digits.length <= 4
// digits[i] is a digit in the range ['2', '9']

// Simple Recursion
#define pb push_back
class Solution {
public:
    vector<string> ans;
    map<char,vector<char> > m;
    void solve(string digits,string s,int i,int n)
    {
        if(i==n){
            ans.pb(s);
            return ;
        }
        for(auto x : m[digits[i]])
        {
            string tmp=s;
            tmp+=x;
            solve(digits,tmp,i+1,n);
        }

    }
    vector<string> letterCombinations(string digits) {
        m['2']={'a','b','c'};
        m['3']={'d','e','f'};
        m['4']={'g','h','i'};
        m['5']={'j','k','l'};
        m['6']={'m','n','o'};
        m['7']={'p','q','r','s'};
        m['8']={'t','u','v'};
        m['9']={'w','x','y','z'};
        int n=digits.length();
        if(n==0) return ans;
        string s="";
        solve(digits,s,0,n);
        return ans;
    }
};