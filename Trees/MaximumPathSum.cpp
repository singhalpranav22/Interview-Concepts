// Given a non-empty binary tree, find the maximum path sum.

// For this problem, a path is defined as any node sequence from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

 

// Example 1:


// Input: root = [1,2,3]
// Output: 6
// Example 2:


// Input: root = [-10,9,20,null,null,15,7]
// Output: 42
 

// Constraints:

// The number of nodes in the tree is in the range [0, 3 * 104].
// -1000 <= Node.val <= 1000

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int find(TreeNode* node,int &res)
    {
        if(node==NULL) return 0;
         int lf=find(node->left,res);
         int rt=find(node->right,res);
        // two cases answer at current node or it should take max of left right and return the max sum above
        int tmp=max(max(lf+node->val,rt+node->val),node->val); // for returning to call below
        res=max(res,max(lf+rt+node->val,max(node->val,tmp))); // considering answer at current node(for all type of cases)
        return tmp; // it return max sum path from that node
    }
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        int noUse=find(root,res);
        return res;
    }
};