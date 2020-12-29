// Implement atoi which converts a string to an integer.

// The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

// The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

// If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

// If no valid conversion could be performed, a zero value is returned.

// Note:

// Only the space character ' ' is considered a whitespace character.
// Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, 231 − 1 or −231 is returned.
 

// Example 1:

// Input: str = "42"
// Output: 42
// Example 2:

// Input: str = "   -42"
// Output: -42
// Explanation: The first non-whitespace character is '-', which is the minus sign. Then take as many numerical digits as possible, which gets 42.
// Example 3:

// Input: str = "4193 with words"
// Output: 4193
// Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
// Example 4:

// Input: str = "words and 987"
// Output: 0
// Explanation: The first non-whitespace character is 'w', which is not a numerical digit or a +/- sign. Therefore no valid conversion could be performed.
// Example 5:

// Input: str = "-91283472332"
// Output: -2147483648
// Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer. Thefore INT_MIN (−231) is returned.
 

// Constraints:

// 0 <= s.length <= 200
// s consists of English letters (lower-case and upper-case), digits, ' ', '+', '-' and '.'.
#define ll long long
class Solution {
public:
    int myAtoi(string s) {
        int valid=0;
        int mx=INT_MAX;
        int mn=INT_MIN;
        int n=s.length();
        ll ans=0;
        int i=0;
        while(i<n && s[i]==' ')
             i++;
        if(i==n) return 0;
        int sign=1;
        if(s[i]<'0' && s[i]>'9' && s[i]!='+' && s[i]!='-')
        {
            return 0;
        }
        if(s[i]=='-')
        {
            sign=0;
            i++;
        }
        else if(s[i]=='+') i++;
        vector<int> v;
        while((s[i]>='0' && s[i]<='9'))
        {
                if(valid==0 && s[i]=='0'){
                    
                }
            else{
                v.push_back(s[i]-'0');
                 valid=1; 
            }
            i++;
            
        }
        if(v.size()==0) return 0;
        int sz=v.size()-1;
        for(auto x : v)
        {
            if(sz>11){
                if(sign==1)
                ans=INT_MAX;
                else 
                    ans=INT_MIN;
                break;
            }
            ans+=x*pow(10,sz);
            
            sz--;
        }
        if(sign==0) {
            ans=(-1)*ans;
            if(ans<mn) return mn;
            else
            {
                int res=ans;
                return res;
            }
            }
        else
        {
            if(ans>mx) return mx;
            else
            {
                int res=ans;
                return res;
            }
        }
        
}};