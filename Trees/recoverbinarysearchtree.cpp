// Two elements of a binary search tree (BST) are swapped by mistake.
// Tell us the 2 values swapping which the tree will be restored.

//  Note:
// A solution using O(n) space is pretty straight forward. Could you devise a constant space solution? 
// Example :


// Input : 
//          1
//         / \
//        2   3

// Output : 
//        [1, 2]

// Explanation : Swapping 1 and 2 will change the BST to be 
//          2
//         / \
//        1   3
// which is a valid BST

// O(1) implementation of the recover binary tree !

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


 void solve(TreeNode *root,int &pre,int &first,int &mid,int &last)
 {
     if(root==NULL) return;
     solve(root->left,pre,first,mid,last);
     if(pre!=-1 && (pre  >  root->val))
     {
         if(first==-1)
           {
               first=pre;
               mid=root->val;
           }
          else
           {
               last=root->val;
           }
     }
     pre=root->val;
     solve(root->right,pre,first,mid,last);
 }
vector<int> Solution::recoverTree(TreeNode* a) {
    int a1=INT_MIN,b1=INT_MIN;
    int first=-1,mid=-1,last=-1;
    int pre=-1;
    solve(a,pre,first,mid,last);
    vector<int> ans;
    if(last==-1)
    {
    ans.push_back(mid);
    ans.push_back(first);
    }
    else
    {
    ans.push_back(last);
    ans.push_back(first);   
    }
    return ans;
}

// Morris Inorder traversal

Lets look at the inorder traversal of the tree.
In the ideal case, the inorder traversal should be sorted. But in this case, because of the swapping 2 cases might arise :
1) A sequence like {1, 4, 3, 7, 9}, where the swapped pair are adjacent to each other. Only one inversion ( Inversion here means pair of integer A[i], A[i+1] where A[i] > A[i+1] ).
2) A sequence like {1, 9, 4, 5, 3, 10} where the swapped pair are not adjacent. 2 inversions. We take the min and max of the inversion numbers and we know the number we need to swap to get the right answer.

Now to figure this out, we need to do an inorder traversal. However, the traditional recursive inorder traversal has memory overhead of the depth of the tree.
Using a stack has the same memory overhead.

So, we need something which does not use recursion or stack and can still do the inorder traversal. This part is a bit tricky. Not all interviewers expect you to know this.
Morris traversal helps us achieve what we are after. It works on the fact that we can modify the tree when traversing and then resetting the tree to its original state once we are done.

The idea of Morris traversal is based on Threaded Binary tree ( http://en.wikipedia.org/wiki/Threaded_binary_tree ).

In this traversal, we first create links to Inorder successor and print the data using these links, and finally revert the changes to restore original tree.

Initialize current as root
While current is not NULL
If current does not have left child
a) Print current’s data
b) Go to the right, i.e., current = current->right
Else
a) Make current as right child of the rightmost node in current’s left subtree
b) Go to this left child, i.e., current = current->left
Although the tree is modified through the traversal, it is reverted back to its original shape after the completion.

// Morris Traversal
TreeNode* InorderPred(TreeNode* root){
    TreeNode* ogl = root;
    root = root->left;
    while(root->right && root->right != ogl){
        root = root->right;
    }
    return root;
}

vector<int> Solution::recoverTree(TreeNode* A) {
    int f = INT_MIN, l = INT_MIN, prev = INT_MIN;
    
    TreeNode* curr = A;
    while(curr != NULL){
        if(curr->left == NULL){
            if(curr->val < prev && f == INT_MIN){
                f = prev;
                l = curr->val;
            }else if(curr->val < prev)l = curr->val;
            prev = curr->val;
            curr = curr->right;
        }else{
            TreeNode* pred = InorderPred(curr);
            if(pred->right != NULL){
                pred->right = NULL;
                if(curr->val < prev && f == INT_MIN){
                f = prev;
                l = curr->val;
            }else if(curr->val < prev)l = curr->val;
            prev = curr->val;
                curr = curr->right;
            }else{
                pred->right = curr;
                curr = curr->left;
            }
            
        }
    }
    vector<int> ans = {l, f};
    return ans;
}
