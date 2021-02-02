// Problem Description

// Given A and B you have to find all stepping numbers in range A to B.

// The stepping number:

// A number is called as a stepping number if the adjacent digits have a difference of 1.

// e.g. 123 is stepping number, but 358 is not a stepping number



// Input Format
// First argument is an integer A.

// Second argument is an integer B.



// Output Format
// Return a integer array sorted in ascending order denoting the stepping numbers between A and B.



// Example Input
// Input 1:

//  A = 10
//  B = 20


// Example Output
// Output 1:

//  [10, 12]


// Example Explanation
// Explanation 1:

//  All stepping numbers are 10 , 12 

// solution like from 24 we can reach 24*10 +4 -1 & 24*10 +4 +1 = 243 &245
void dfs(int num,vector<int> &ans,int A,int B)
{
    if(num>B) return;
    int x=-1,y=-1;
    if(num>=A && num<=B) ans.push_back(num);
    int lastD=num%10;
    if(lastD!=0)
    {
      x=num*10+lastD-1;
      
       dfs(x,ans,A,B);
    }
    if(lastD!=9)
    {
     y=num*10+lastD+1;
     
     dfs(y,ans,A,B);
    }
    
}
vector<int> Solution::stepnum(int A, int B) {
    vector<int> ans;
    if(A==0) ans.push_back(0);
    for(int i=1;i<=9;i++) dfs(i,ans,A,B);
    sort(ans.begin(),ans.end());
    return ans;
    
}
