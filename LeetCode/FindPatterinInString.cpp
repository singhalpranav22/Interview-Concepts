// KMP ALGORITHM IS USED FOR THIS PROBLEM
// Implement strStr().

// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Clarification:

// What should we return when needle is an empty string? This is a great question to ask during an interview.

// For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

 

// Example 1:

// Input: haystack = "hello", needle = "ll"
// Output: 2
// Example 2:

// Input: haystack = "aaaaa", needle = "bba"
// Output: -1
// Example 3:

// Input: haystack = "", needle = ""
// Output: 0
 

// Constraints:

// 0 <= haystack.length, needle.length <= 5 * 104
// haystack and needle consist of only lower-case English characters.

class Solution {
public:
    int strStr(string s, string pat) {
        int n=s.length();
        int m=pat.length();
        if(m==0) return 0;
        int lps[m];
        int i=1;
        int len=0;
        lps[0]=0;
        // pat-> “AAACAAAAAC”
        // lps-> "0120123334"
        while(i<m) // Calculation of lps array
        {
            if(pat[len]==pat[i])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else
            {
                if(len!=0) // dont increment i
                {
                    len=lps[len-1]; // PREVIOUS PREFIX THAT MATCH WITH CURRENT SUFFIX
                }
                else
                {
                    lps[i]=0;
                    i++;
                }
            }
        }
        i=0;
        int j=0;
        while(i<n) //i is for s and j for patt, j is decided based on the lps array which tells whether thr current suffix is part of a prefix in the string
        {
            if(s[i]==pat[j])
            {
                i++;
                j++;
            }
            else
            {
                if(j==0)
                {
                    i++;
                }
                else
                {
                    j=lps[j-1];
                }
            }
            if(j==m)
            {
                return i-m;
            }
        }
        return -1;
    }
};