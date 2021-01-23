/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode* A,vector<int> &v)
{
    if(A==NULL)return;
    v.push_back(A->val);
    solve(A->left,v);
    solve(A->right,v);
}
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> ans;
    solve(A,ans);
    return ans;
}
