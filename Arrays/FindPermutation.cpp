// Given a positive integer n and a string s consisting only of letters D or I, you have to find any permutation of first n positive integer that satisfy the given input string.

// D means the next number is smaller, while I means the next number is greater.

// Notes

// Length of given string s will always equal to n - 1
// Your solution should run in linear time and space.
// Example :

// Input 1:

// n = 3

// s = ID

// Return: [1, 3, 2]

vector<int> Solution::findPerm(const string s, int b) {
    int big=b;
    int small=1;
    vector<int> ans;
    for(int i=0;i<s.length();i++)
    {
         if(s[i]=='D')
           ans.push_back(big--);
         else
            ans.push_back(small++);
    }
    ans.push_back(small);
    return ans;
    
}
