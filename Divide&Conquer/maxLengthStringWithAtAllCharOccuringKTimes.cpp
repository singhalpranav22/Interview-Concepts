Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.

 

Example 1:

Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
 

Constraints:

1 <= s.length <= 104
s consists of only lowercase English letters.
1 <= k <= 105

class Solution {
public:
    int find(string s,int l,int r,int k){
        int hsh[26]={0};
        for(int i=l;i<=r;i++) hsh[s[i]-'a']++;
        for(int i=l;i<=r;i++){
            if(hsh[s[i]-'a']<k){
                int j=i+1;
                while(j<=r && hsh[s[j]-'a']<k) j++;
                return max(find(s,l,i-1,k),find(s,j,r,k));
            }
        }
        return r-l+1;
    }
    int longestSubstring(string s, int k) {
        return find(s,0,s.length()-1,k);
    }
};

