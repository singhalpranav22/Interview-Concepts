// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

 

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
 

// Constraints:

// 0 <= strs.length <= 200
// 0 <= strs[i].length <= 200
// strs[i] consists of only lower-case English letters.


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        if(strs.size()<=0) return ans;
        ans=strs[0];
        for(int i=1;i<strs.size();i++)
        {
            string tmp="";
            for(int j=0;j<strs[i].length(),j<ans.length();j++){
                if(ans[j]==strs[i][j]) tmp+=ans[j];
                else
                {
                    ans=tmp;
                    break;
                }
            }
        }
        return ans;
    }
};