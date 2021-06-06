// Problem Description

// Given an integer A find the Ath number whose binary representation is a palindrome.

// NOTE:

// Consider the 1st number whose binary representation is palindrome as 1, instead of 0
// Do not consider the leading zeros, while considering the binary representation.


// Problem Constraints
// 1 <= A <= 2104



// Input Format
// First and only argument is an integer A.



// Output Format
// Return an integer denoting the Ath number whose binary representation is a palindrome.



// Example Input
// Input 1:

//  A = 1
// Input 1:

//  A = 9


// Example Output
// Output 1:

//  1
// Output 2:

//  27


// Example Explanation*
// Explanation 1:

//  1st Number whose binary representation is palindrome is 1
// Explanation 2

//  9th Number whose binary representation is palindrome is 27 (11011)



int Solution::solve(int A) {
    if(A==1) return 1;
    int k = 1;
    queue<string> q;
    q.push("11");
    while(!q.empty()){
        string s = q.front();
        q.pop();
        k++;
        if(k==A){
         int po=1;
         int ans=0;
         for(int i=s.length()-1;i>=0;i--){
             ans+=(s[i]-'0')*po;
             po*=2;
         }
         return ans;
        }
        int sz = s.length();
        int mid = sz/2;
        if(sz%2==0){
            string newa = "" , newb;
            for(int i=0;i<mid;i++){
                newa+=s[i];newb+=s[i];
            }
            newa+='0',newb+='1';
            for(int i=mid;i<sz;i++){
                newa+=s[i],newb+=s[i];
            }
            q.push(newa);
            q.push(newb);
            
        }
        else{
            char ch = s[mid];
            string newa="";
            for(int i=0;i<=mid;i++) newa+=s[i];
            newa+=ch;
            for(int i=mid+1;i<sz;i++) newa+=s[i];
            q.push(newa);
        }
    }
    return 1;
}
