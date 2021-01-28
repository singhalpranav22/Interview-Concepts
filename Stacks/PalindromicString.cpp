// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

// Example:

// "A man, a plan, a canal: Panama" is a palindrome.

// "race a car" is not a palindrome.

// Return 0 / 1 ( 0 for false, 1 for true ) for this problem

int Solution::isPalindrome(string s) {
     int n=s.length();
     int i=0,j=n-1;
     int f=1;
     while(i<n && j>=0)
     {
         while(i<n && !(s[i]>='0' && s[i]<='9' || isalpha(s[i])))
         {
         i++;
         }
        while(j>=0 && !(s[j]>='0' && s[j]<='9' || isalpha(s[j]))) {
            j--;
           
        }
         if(i<n && j>=0)
           {
               char a,b;
               if(isalpha(s[i])) a=tolower(s[i]);
                if(isalpha(s[j])) b=tolower(s[j]);
            //    cout<<a<<" "<<b<<nl;
               if(a!=b) return 0;
               i++;
               j--;
           }
           else
            break;
     }
     return f;
}
