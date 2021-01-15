// Given the array of strings A,
// you need to find the longest string S which is the prefix of ALL the strings in the array.

// Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1
// and S2.

// For Example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".



// Input Format

// The only argument given is an array of strings A.
// Output Format

// Return longest common prefix of all strings in A.
// For Example

// Input 1:
//     A = ["abcdefgh", "aefghijk", "abcefgh"]
// Output 1:
//     "a"
//     Explanation 1:
//         Longest common prefix of all the strings is "a".

// Input 2:
//     A = ["abab", "ab", "abcd"];
// Output 2:
//     "ab"
//     Explanation 2:
//         Longest common prefix of all the strings is "ab".

// Bad Solution
// string Solution::longestCommonPrefix(vector<string> &A) {
//         string ans = A[0];
//         int n = A.size();
//         for (int i = 1; i < n; i++) {
//             int curr = min(ans.size(), A[i].size());
//             while (ans.substr(0, curr) != A[i].substr(0, curr)) {
//                 curr--;
//             }
//             if (curr < 0) curr = 0;
//             ans = ans.substr(0, curr);
//         }
//         return ans;
//     }

// Sort the strings than check the smalles and longest strings for ans

string Solution::longestCommonPrefix(vector<string> &A) 
{
    string s;
    //sorting the strings lexicographically 
    sort(A.begin(),A.end());
    int m,n;
    m=A.size()-1;
    n=min(A[0].length(),A[m].length());
    int i=0;
    //first and last string will be most dissimilar thus finding common charcters in these
    while(i<n && A[0][i]==A[m][i])
    {
        s+=A[0][i];
        i++;
    }
    return s;
}
