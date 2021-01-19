// Problem Description

// Given a Binary Tree A containing N nodes.

// You need to find the path from Root to a given node B.

// NOTE:

// No two nodes in the tree have same data values.
// You can assume that B is present in the tree A and a path always exists.


// Problem Constraints
// 1 <= N <= 105

// 1 <= Data Values of Each Node <= N

// 1 <= B <= N



// Input Format
// First Argument represents pointer to the root of binary tree A.

// Second Argument is an integer B denoting the node number.



// Output Format
// Return an one-dimensional array denoting the path from Root to the node B in order.



// Example Input
// Input 1:

//  A =

//            1
//          /   \
//         2     3
//        / \   / \
//       4   5 6   7 


// B = 5

// Input 2:

//  A = 
//             1
//           /   \
//          2     3
//         / \ .   \
//        4   5 .   6


// B = 1




// Example Output
// Output 1:

//  [1, 2, 5]
// Output 2:

//  [1]


// Example Explanation
// Explanation 1:

//  We need to find the path from root node to node with data value 5.
//  So the path is 1 -> 2 -> 5 so we will return [1, 2, 5]
// Explanation 2:

//  We need to find the path from root node to node with data value 1.
//  As node with data value 1 is the root so there is only one node in the path.
//  So we will return [1]


// Bad solution using a vector in every call:

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
void fun(TreeNode *A,int B,vector<int> v)
{
    if(A==NULL) return;
    v.push_back(A->val);
    if(A->val==B)
    {
        ans=v;
        return;
    }
    fun(A->left,B,v);
    fun(A->right,B,v);
    
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> v;
    fun(A,B,v);
    return ans;
}


// Good Solution :

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Also checks if the node present or not with value B
bool fun(TreeNode *A,int B,vector<int> &v)
{
    if(A==NULL) return false; // B not found
    if(A->val==B)
    {
        v.push_back(B);
        return true; // B found
    }
    if(fun(A->left,B,v) || fun(A->right,B,v)) // B found in left or right subtree than push it in the vector
    {
        v.push_back(A->val);
        return true;
    }
    return false;
    
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> v;
    fun(A,B,v);
    reverse(v.begin(),v.end());
    return v;
}
