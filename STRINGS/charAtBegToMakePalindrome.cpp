// KMP ALERT!!!

Given an string A. The only operation allowed is to insert characters in the beginning of the string.

Find how many minimum characters are needed to be inserted to make the string a palindrome string.



Input Format

The only argument given is string A.
Output Format

Return the minimum characters that are needed to be inserted to make the string a palindrome string.
For Example

Input 1:
    A = "ABC"
Output 1:
    2
    Explanation 1:
        Insert 'B' at beginning, string becomes: "BABC".
        Insert 'C' at beginning, string becomes: "CBABC".

Input 2:
    A = "AACECAAAA"
Output 2:
    2
    Explanation 2:
        Insert 'A' at beginning, string becomes: "AAACECAAAA".
        Insert 'A' at beginning, string becomes: "AAAACECAAAA".




        // By : Pranav Singhal
// IIIT-Allahabad
int Solution::solve(string s) {
    // we will match with lps array, in reverse we would check max length suffix which is a prefix in original string
      // if input is AACECAAAA make it of the form as given : Original + $ + reverse
    // AACECAAAA$AAAACECAA
    // 0100012220122234567  -> lps array
    // the last index of this lps array tells how much length of the original string from starting is a palindrome, we only need to add the remaining letters in the start to make a palondrome
    string r = s;
    reverse(r.begin(),r.end());
    int orgL=s.length();
    s = s + "$" + r;
    int l = s.length();
    int lps[l]; // lps array
    int len=0,i=1;
    lps[0]=0;
    while(i<l){
        if(s[len]==s[i]){
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0){
                len=lps[len-1];
            }
            else{
                len=0;
                lps[i]=0;
                i++;
            }
        }
    }
    int suff = lps[l-1]; // last index 
    return orgL-suff; // original length - last index of lps array
}

