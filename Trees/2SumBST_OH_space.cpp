// Given a binary search tree T, where each node contains a positive integer, and an integer K, you have to find whether or not there exist two different nodes A and B such that A.value + B.value = K.

// Return 1 to denote that two such nodes exist. Return 0, otherwise.

// Notes

// Your solution should run in linear time and not take memory more than O(height of T).
// Assume all values in BST are distinct.
// Example :

// Input 1: 

// T :       10
//          / \
//         9   20

// K = 19

// Return: 1

// Input 2: 

// T:        10
//          / \
//         9   20

// K = 40

// Return: 0

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // Solved using inorder iterative version,one ascending L-V-R & other descending R-V-L
 // Time-O(n) and space O(height of tree)
int Solution::t2Sum(TreeNode* A, int B) {
    stack<TreeNode*> l,r;
    TreeNode* lft=A;
    TreeNode* rgt=A;
    
    while(lft!=NULL) // lft stack initialisation
    {
     l.push(lft);
     lft=lft->left;
    }
    while(rgt!=NULL)  // right stack initialisation for inorder traversal
    {
        r.push(rgt);
        rgt=rgt->right;
    }
    if(l.size()==0 || r.size()==0) return 0;
    int lval=l.top()->val,rval=r.top()->val;
    int f=0;
    //  lvalue(l,lval,lft);
    //  rvalue(r,rval,rgt);
    while(lval<rval)  // Two pointer technique to find the sum while doing inorder traversal
    {
    if(lval+rval==B)
    {
        f=1;
        break;
    }
    if(lval+rval<B)
    {
        TreeNode* temp=l.top();
        l.pop();
        temp=temp->right; // right subtree
        while(temp!=NULL)
        {
            l.push(temp);
            temp=temp->left;
        }
        lval=l.top()->val;
    }
    else
    {
        TreeNode* temp=r.top();
        r.pop();
        temp=temp->left; // left subtree
        while(temp!=NULL)
        {
            r.push(temp);
            temp=temp->right;
        }
        rval=r.top()->val;
    }
         
    }
    return f;
}
