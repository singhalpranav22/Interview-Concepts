/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void solve(TreeNode *a)
{
     if(a==NULL) return ;
    if(a->left==NULL && a->right!=NULL)
        {
            a->left=a->right;
            a->left=NULL;
        }
    else if(a->left!=NULL && a->right==NULL)
        {
            a->right=a->left;
            a->right=NULL;
        }
    else if(a->left==NULL && a->right==NULL)
       return ;
    TreeNode *temp=a->right;
    a->right=a->left;
    a->left=temp;
    solve(a->left);
    solve(a->right);
    return ;
}
TreeNode* Solution::invertTree(TreeNode* a) {
   
        solve(a);
        return a;
}