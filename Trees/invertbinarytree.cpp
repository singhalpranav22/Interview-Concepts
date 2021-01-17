// Given a binary tree, invert the binary tree and return it.
// Look at the example for more details.

// Example :
// Given binary tree

//      1
//    /   \
//   2     3
//  / \   / \
// 4   5 6   7
// invert and return

//      1
//    /   \
//   3     2
//  / \   / \
// 7   6 5   4

// WORKING->SWAP LEFT RIGHT AT EVERY NODE
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode* sset(TreeNode* root,int data)
{
    struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode)); 
    root->val=data;
    root->left=NULL;
    root->right=NULL;
    
    return (node);
}
void dfs(TreeNode* root,TreeNode* ans)
{
    
    if(root==NULL)
    {
        return;
    }
    ans=sset(ans,(root->val));
    
    // if((root->left)!=NULL)
    dfs((root->left),(ans->right));
    // if((root->right)!=NULL)
    dfs((root->right),(ans->left));
}

TreeNode* Solution::invertTree(TreeNode* A) {
    TreeNode* ans;
    ans=NULL;
    
    dfs(A,ans);
    
    return ans;
}
