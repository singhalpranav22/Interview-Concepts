// We can scramble a string s to get a string t using the following algorithm:

// If the length of the string is 1, stop.
// If the length of the string is > 1, do the following:
// Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
// Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
// Apply step 1 recursively on each of the two substrings x and y.
// Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.

 

// Example 1:

// Input: s1 = "great", s2 = "rgeat"
// Output: true
// Explanation: One possible scenario applied on s1 is:
// "great" --> "gr/eat" // divide at random index.
// "gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep them in order.
// "gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at ranom index each of them.
// "g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
// "r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
// "r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
// The algorithm stops now and the result string is "rgeat" which is s2.
// As there is one possible scenario that led s1 to be scrambled to s2, we return true.
// Example 2:

// Input: s1 = "abcde", s2 = "caebd"
// Output: false
// Example 3:

// Input: s1 = "a", s2 = "a"
// Output: true
 

// Constraints:

// s1.length == s2.length
// 1 <= s1.length <= 30
// s1 and s2 consist of lower-case English letters.

// Solution Explanation :
// gr|eat   rgeat
// Case 1: no swap b/w gr & eat
// check for (gr & rg) && (eat & eat) are sramble strings or not
// Case 2 : Swap b/w gr & eat
// Check for (gr & at(from last of string 2)) && (eat & rge(first from string 1)) are scramble strings or not
// Check if any of them comes true, than function returns true
// Do this recursively for finding the result
// shorter version of the code
int Solution::isScramble(const string A, const string B) {
if(A.length()!=B.length())
return 0;
int n=A.length();
if(n==0)
return 1;
if(A==B)
return 1;
string copy_A=A,copy_B=B;
sort(copy_A.begin(),copy_A.end());
sort(copy_B.begin(),copy_B.end());
if(copy_A!=copy_B)
return 0;
for(int i=1;i<n;i++)
{
if(isScramble(A.substr(0,i),B.substr(0,i))&&isScramble(A.substr(i,n-i),B.substr(i,n-i)))
return 1;
if(isScramble(A.substr(0,i),B.substr(n-i,i))&&isScramble(A.substr(i,n-i),B.substr(0,n-i)))
return 1;
}
return 0;

}
// longer version of the code
 class Solution {
public:
     bool sameChar(string S1,string S2) // function to check if the two strings have same frequencies of character
     {
         int s1Array[26] ={0} ;
         int s2Array[26] ={0};
         
    for(int i = 0; i < S1.length(); i++) {
        s1Array[S1[i] - 'a']++;
        s2Array[S2[i] - 'a']++;
    }
    for(int i = 0; i < 26; i++){
        if( s1Array[i] != s2Array[i] )
        {
            return false;
        }
            
    }
        

          return true;

     }
     unordered_map<string,bool> m1;
    bool isScramble(string s1, string s2) {
       
        if(s1.length()!=s2.length())return false;
        if(s1.length()==0) return false;
        if(s1.length()==1 && s1!=s2) return false;
        if(s1.length()==1 && s1==s2) return true;
        if(s1.compare(s2)==0) return true;
         if(sameChar(s1,s2)==false) return false; // to check if the two strings have same frequencies of characters or not in order to avoid unecessary calls
        string key=s1+" "+s2;
        if(m1.find(key)!=m1.end())
              return m1[key];
        int n=s1.length();
        bool flag=false;
        for(int i=1;i<n;i++)
        {
            // no swap case (compare the first half & second half to other for scramble)
            string s1f=s1.substr(0,i),s1s=s1.substr(i,n-i);
            string s2f=s2.substr(0,i),s2s=s2.substr(i,n-i);
            string key=s1f+" "+s2f;
            bool b1,b2;
            if(m1.find(key)!=m1.end())
            {
                b1=m1[key];
            }
            else{
                b1=isScramble(s1f,s2f);
                m1[key]=b1;
               
            }
            key=s1s+" "+s2s;
              if(m1.find(key)!=m1.end())
            {
                b2=m1[key];
            }
            else{
                b2=isScramble(s1s,s2s);
                m1[key]=b2;
                
            }
            bool noSwap=(b1&&b2);
            // swap case
            string a=s1.substr(0,i);
            string b=s2.substr(n-i,i);
            key=a+" "+b;
             if(m1.find(key)!=m1.end())
            {
                b1=m1[key];
            }
            else{
                b1=isScramble(a,b);
                m1[key]=b1;
            }
           
            a=s1.substr(i,n-i);
            b=s2.substr(0,n-i);
            key=a+" "+b;
             if(m1.find(key)!=m1.end())
            {
                b2=m1[key];
            }
            else{
                b2=isScramble(a,b);
                m1[key]=b2;
            }
            bool Swap=(b1&&b2);
            if(noSwap||Swap){
                flag=true;
                break;
            }
            
            
        }
        
        return m1[key]=flag;
    }
};