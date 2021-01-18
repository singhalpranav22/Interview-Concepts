// Problem Description

// Given a binary tree A with N nodes.

// You have to remove all the half nodes and return the final binary tree.

// NOTE:

// Half nodes are nodes which have only one child.
// Leaves should not be touched as they have both children as NULL.


// Problem Constraints
// 1 <= N <= 105



// Input Format
// First and only argument is an pointer to the root of binary tree A.



// Output Format
// Return a pointer to the root of the new binary tree.



// Example Input
// Input 1:

//            1
//          /   \
//         2     3
//        / 
//       4

// Input 2:

//             1
//           /   \
//          2     3
//         / \     \
//        4   5     6


// Example Output
// Output 1:

//            1
//          /    \
//         4      3
// Output 2:

//             1
//           /   \
//          2     6
//         / \

//        4   5



// Example Explanation
// Explanation 1:

//  The only half node present in the tree is 2 so we will remove this node.
// Explanation 2:

//  The only half node present in the tree is 3 so we will remove this node.

// The idea is to use post-order traversal to solve this problem efficiently.
// We first process the left children, then right children, and finally the node itself.
// So we form the new tree bottom up, starting from the leaves towards the root.
// By the time we process the current node, both its left and right subtrees were already processed.

// Time complexity of the above solution is O(N) as it does a simple traversal of binary tree.

My Preorder solution :
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 TreeNode *head;
 void fun(TreeNode *a,TreeNode *prev,int f) // f=0(left) & f=1(right)
 {
     if(a==NULL) return;
     while((a->left==NULL && a->right!=NULL) || (a->left!=NULL && a->right==NULL))
     {
         if(a->left==NULL)
          {
              if(prev!=NULL)
                {
                    if(f==0)
                       {
                           prev->left=a->right;
                       }
                      else
                      {
                          prev->right=a->right;
                      }
                }
                if(prev==NULL)
                  head=a->right;
                a=a->right;
          }
          else if(a->right==NULL)
          {
              if(prev!=NULL)
                {
                    if(f==0)
                       {
                           prev->left=a->left;
                       }
                      else
                      {
                          prev->right=a->left;
                      }
                }
                if(prev==NULL)
                head=head->left;
                a=a->left;
          }

     }
     fun(a->left,a,0);
     fun(a->right,a,1);
 }
TreeNode* Solution::solve(TreeNode* a) {
    TreeNode *prev=NULL;
    head=a;
    fun(a,prev,0);
    return head;
}

// Postorder solution
// The idea is to use post-order traversal to solve this problem efficiently.
// We first process the left children, then right children, and finally the node itself.
// So we form the new tree bottom up, starting from the leaves towards the root.
// By the time we process the current node, both its left and right subtrees were already processed.

// Time complexity of the above solution is O(N) as it does a simple traversal of binary tree.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::solve(TreeNode* A) {
    if(A->left == NULL && A->right == NULL)return A;
    if(A->left == NULL)
        return solve(A->right);
    if(A->right == NULL)
        return solve(A->left);
    A->left = solve(A->left);
    A->right = solve(A->right);
    return A;
    
}

