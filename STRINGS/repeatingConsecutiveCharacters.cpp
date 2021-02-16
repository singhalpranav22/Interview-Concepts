//     Problem Description

// Given a string A and integer B, remove all consecutive same characters that have length exactly B.



// Problem Constraints
// 1 <= |A| <= 100000

// 1 <= B <= |A|



// Input Format
// First Argument is string A.

// Second argument is integer B.



// Output Format
// Return a string after doing the removals.



// Example Input
// Input 1:

// A = "aabcd"
// B = 2
// Input 2:

// A = "aabbccd"
// B = 2


// Example Output
// Output 1:

//  "bcd"
// Output 2:

//  "d"


// Example Explanation
// Explanation 1:

//  "aa" had length 2.
// Explanation 2:

//  "aa", "bb" and "cc" had length of 2.

string Solution::solve(string s, int B) {
    char curr=s[0];
    int len=1;
    int ind=0;
    string ans;
    for(int i=1;i<s.length();i++)
    {
        if(s[i]==curr)
        {
            len++;
        }
        if(s[i]!=curr)
        {
            if(len!=B)
            {
             for(int k=ind;k<=i-1;k++) ans+=s[k];
            }
            curr=s[i];
            len=1;
            ind=i;
        }
    }
     if(len!=B)
            {
             for(int k=ind;k<=s.length()-1;k++) ans+=s[k];
            }
    return ans;
}
