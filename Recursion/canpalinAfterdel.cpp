// Generic function for finding if a string can be a palindrome after at most num deletions.
  bool solve(string s,int l,int r,int num){
        if(l>r) return true;
        if(s[l]==s[r]) return solve(s,l+1,r-1,num);
        else
        {
            
            if(num>0){
                if(s[l+1]==s[r] && s[l]==s[r-1])
                return solve(s,l+1,r,num-1) || solve(s,l,r-1,num-1);
                else if(s[l+1]==s[r])
                    return solve(s,l+1,r,num-1);
                else if(s[l]==s[r-1])
                    return solve(s,l,r-1,num-1);
                else return false;
            }
            else
                return false;
        }
              
    }
    bool validPalindrome(string s) {
       int num = 1;
        return solve(s,0,s.length()-1,num);
    }