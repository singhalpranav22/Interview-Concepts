// Given A, generate all structurally unique BST’s (binary search trees) that store values 1…A.

// Input Format:

// The first and the only argument of input contains the integer, A.
// Output Format:

// Return a list of tree nodes representing the generated BST's.
// Constraints:

// 1 <= A <= 15
// Example:

// Input 1:
//     A = 3

// Output 1:

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3


vector<TreeNode*> solve(int l,int r){
    if(l>r) return {NULL};
    vector<TreeNode*> ans;
    for(int i=l;i<=r;i++){
        vector<TreeNode*> left = solve(l,i-1);
        vector<TreeNode*> right = solve(i+1,r);
        for(int j=0;j<left.size();j++){
            for(int k=0;k<right.size();k++){
                TreeNode* root = new TreeNode(i);
                root->left=left[j];
                root->right=right[k];
                ans.push_back(root);
            }
        }
    }
    return ans;
}
vector<TreeNode*> Solution::generateTrees(int A) {
    vector<TreeNode*> res=solve(1,A);
    return res;
    
}