// Given two strings s and t, return the minimum window in s which will contain all the characters in t. If there is no such window in s that covers all characters in t, return the empty string "".

// Note that If there is such a window, it is guaranteed that there will always be only one unique minimum window in s.

 

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
 

// Constraints:

// 1 <= s.length, t.length <= 105
// s and t consist of English letters.
 

// Follow up: Could you find an algorithm that runs in O(n) time?

class Solution {
public:
    unordered_map<char,int> tm;
    unordered_map<char,int> sm;
    bool isDesirable()
    {
        bool ans=true;
        for(auto x: tm)
        {
            if(sm[x.first]>=x.second) continue;
            else{
               ans=false;
                break;
            }
        }
        return ans;
    }
    string minWindow(string s, string t) {
        int i=0,j=-1;
        int ans=0;
        int ansi=-1;
        int ansj=0;
        int f=0;
        int n=s.length();
        for(int i=0;i<t.length();i++)
             tm[t[i]]++;
        int currmn=INT_MAX;
        while(i<n && j<n)
        {
            
            while(j<n)
            {
                 j++;
                sm[s[j]]++;
                if(isDesirable()) break;
               
            }
            if(isDesirable())
            {
                if(j-i+1<currmn)
                {
                    currmn=j-i+1;
                    ansi=i;
                    ansj=j;
                }
            }
            while(i<n && i<=j)
            {
                sm[s[i]]--;
                i++;
                if(isDesirable()==false)
                     break;
                if(j-i+1<currmn)
                {
                    currmn=j-i+1;
                    ansi=i;
                    ansj=j;
                }
                
            }
        }
        if(ansi!=-1)
        {
            string ans;
            for(int i=ansi;i<=ansj;i++) ans+=s[i];
            return ans;
        }
        else
            return "";
        
    }
};