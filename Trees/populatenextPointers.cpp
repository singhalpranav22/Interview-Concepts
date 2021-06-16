// Given a binary tree

//     struct TreeLinkNode {
//       TreeLinkNode *left;
//       TreeLinkNode *right;
//       TreeLinkNode *next;
//     }
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL.

//  Note:
// You may only use constant extra space.
// Example :

// Given the following binary tree,

//          1
//        /  \
//       2    3
//      / \  / \
//     4  5  6  7
// After calling your function, the tree should look like:

//          1 -> NULL
//        /  \
//       2 -> 3 -> NULL
//      / \  / \
//     4->5->6->7 -> NULL

// Solution : 
// Lets say you have already created next pointers till level L. To create next pointer for level L+1, start with the first node on level L.

//         1   ->  2   ->  3  -> 4
//        /         \           / \
//       /           \         /    \ 
//      5            6        7      8 
        

//         1   ->  2   ->  3  -> 4
//        /         \           / \
//       /           \         /   \ 
//      4     ->      7   ->  8 ->  9 
// Keep track of the previous node you encountered on the next level. For the current node, explore the left and right child if they are not null in that order. If the prev is not set, that means we are looking at the leftmost node on the next level ( Lets store it because we will begin the next iteration from this node ). Else you can assign prev->next as the current node in next level you are exploring and update the prev node.

void Solution::connect(TreeLinkNode* A) {
    TreeLinkNode *start=NULL, *prev = NULL;
     while(A){
         if(A->left){
             if(prev) prev->next = A->left;
             else start=A->left;
             prev = A->left;
         }
         if(A->right){
             if(prev) prev->next = A->right;
             else start=A->right;
             prev = A->right;
         }
         if(A->next) A=A->next;
         else {
             A=start;
             start = NULL;
             prev = NULL;
         }
     }
 }