// Given two binary trees, write a function to check if they are equal or not.

// Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

// Return 0 / 1 ( 0 for false, 1 for true ) for this problem

// Example :

// Input : 

//    1       1
//   / \     / \
//  2   3   2   3

// Output : 
//   1 or True

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int f=1;
 
 void solve(TreeNode *a,TreeNode *b)
 {
     if(a==NULL && b==NULL) return ;
     if((a==NULL && b!=NULL) || (a!=NULL && b==NULL) || (a->val != b->val)){
         f=0;
         return;
     }
     solve(a->left,b->left);
     solve(a->right,b->right);
     
 }
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    f=1;
    solve(A,B);
    return f;
}
