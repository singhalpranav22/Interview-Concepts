// Problem Description

// Given a binary tree A of integers. Return an array of integers representing the right view of the Binary tree.

// Right view of a Binary Tree: is a set of nodes visible when the tree is visited from Right side.



// Problem Constraints
// 1 <= Number of nodes in binary tree <= 105

// 0 <= node values <= 109



// Input Format
// First and only argument is an pointer to the root of binary tree A.



// Output Format
// Return an integer array denoting the right view of the binary tree A.



// Example Input
// Input 1:

//         1
//       /   \
//      2    3
//     / \  / \
//    4   5 6  7
//   /
//  8 
// Input 2:

//     1
//    /  \
//   2    3
//    \
//     4
//      \
//       5


// Example Output
// Output 1:

//  [1, 3, 7, 8]
// Output 2:

//  [1, 3, 4, 5]


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> ans;
vector<int> Solution::solve(TreeNode* A) {
    ans.clear();
    map<int,int> m;
    queue <pair<TreeNode*,int> > q;
    int lev=0;
    q.push(make_pair(A,lev));
    while(!q.empty())
    {
        TreeNode *temp=q.front().first;
        int level=q.front().second;
        q.pop();
        if(m[level]==0)
        {
            ans.push_back(temp->val);
            m[level]=1;
        }
        
        if(temp->right!=NULL)
         q.push(make_pair(temp->right,level+1));
        if(temp->left!=NULL)
         q.push(make_pair(temp->left,level+1));
        
        }
        return ans;
}

