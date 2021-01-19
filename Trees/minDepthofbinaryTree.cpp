// Given a binary tree, find its minimum depth.

// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

//  NOTE : The path has to end on a leaf node. 
// Example :

//          1
//         /
//        2
// min depth = 2.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode* A) {
     if(A==NULL) return INT_MAX-100;
     if(A->left==NULL && A->right==NULL) return 1;
    int left=minDepth(A->left)+1; // Height of Left Subtree
    int right=minDepth(A->right)+1; // Height of Right Subtree
    return min(left,right);
}
