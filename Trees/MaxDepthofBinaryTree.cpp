// Given a binary tree, find its maximum depth.

// The maximum depth of a binary tree is the number of nodes along the longest path from the root node down to the farthest leaf node.

//  NOTE : The path has to end on a leaf node. 
// Example :

//          1
//         /
//        2
// max depth = 2.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::maxDepth(TreeNode* A) {
    if(A==NULL) return 0;
    int left=maxDepth(A->left)+1; // Height of Left Subtree
    int right=maxDepth(A->right)+1; // Height of Right Subtree
    return max(left,right);
}
