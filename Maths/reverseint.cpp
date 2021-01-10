// Find if and integer is palindrome

int reverse(int A) {
    int rev=0;
    while(A>0) {
        rev=rev*10+A%10;
        A=A/10;
    }
return rev;
}

int Solution::isPalindrome(int A) {
   return A==reverse(A);
}