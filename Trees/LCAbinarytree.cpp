// LCA in a Binary tree
// Find path uptill the key, than compare the paths for the first mismatch
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // without use of vector : 

 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* find(TreeNode *root,TreeNode *p,TreeNode *q){
        if(root==NULL) return NULL;
        if(root==p) return p;
        if(root==q) return q;
        TreeNode* lf=find(root->left,p,q),*rt=find(root->right,p,q);
        if(lf!=NULL && rt!=NULL) {
            return root; 
        }
        if(lf==NULL && rt==NULL) return NULL;
        if(lf==NULL) return rt;
        if(rt==NULL) return lf;
        return NULL; // faltu me likha
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return find(root,p,q);

    }
};

// With vector
 bool findPath(TreeNode *root,int k,vector<int> &path) // Find path to a key, and store it in a vector
 {
     if(root==NULL) return false;
     path.push_back(root->val);
     if(root->val==k) return true;
     if((findPath(root->left,k,path) || findPath(root->right,k,path))) return true;
     
     path.pop_back(); // pop the root as the k is not present in either of the left or right subtree
     return false;
 }
int Solution::lca(TreeNode* root, int b, int c) {
    vector<int> bpath,cpath;
    if(!findPath(root,b,bpath) || !findPath(root,c,cpath)) return -1; // if one of the node is not present
    int i=0;
    for(;i<bpath.size() && i<cpath.size() ; i++) // find the first mismatch
    {
        if(bpath[i]!=cpath[i]) break;
    }
    return bpath[i-1]; //returns the val stored at LCA
}
