// Problem Description

// You are given a preorder traversal A, of a Binary Search Tree.

// Find if it is a valid preorder traversal of a BST.



// Problem Constraints
// 1 <= A[i] <= 106

// 1 <= |A| <= 105



// Input Format
// First and only argument is an integer array A denoting the pre-order traversal.



// Output Format
// Return an integer:

// 0 : Impossible preorder traversal of a BST
// 1 : Possible preorder traversal of a BST


// Example Input
// Input 1:

// A = [7, 7, 10, 10, 9, 5, 2, 8]


// Example Output
// Output 1:

//  1

// USE stack to know what is the next greater and the elements next to the next greater should be greater than current root

int Solution::solve(vector<int> &a) {
    int root=INT_MIN;
    stack<int> s;
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        if(root>a[i])
           return false;
         while(s.size()>0 && s.top()<a[i])
         {
             root=s.top();
             s.pop();
         }
         s.push(a[i]);
    }
    return true;
}
