// Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

// Example :

// Given the below binary tree and sum = 22,

//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \      \
//         7    2      1
// return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

// Return 0 / 1 ( 0 for false, 1 for true ) for this problem

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int f=0;
void solve(TreeNode* A,int B,int sum)
{
    if(A==NULL)
    {
        return ;
    }
    if(A->left==NULL && A->right==NULL)
    {
        if(sum + A->val == B) f=1;
        
        return ;
    }
    solve(A->left,B,sum+A->val);
    solve(A->right,B,sum+A->val);
}
int Solution::hasPathSum(TreeNode* A, int B) {
    f=0;
    solve(A,B,0);
    return f;
}
