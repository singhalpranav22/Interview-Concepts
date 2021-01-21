// Problem Description

// Given a Binary Tree A consisting of N nodes.

// You need to find all the cousins of node B.

// NOTE:

// Siblings should not be considered as cousins.
// Try to do it in single traversal.
// You can assume that Node B is there in the tree A.
// Order doesn't matter in the output.


// Problem Constraints
// 1 <= N <= 105

// 1 <= B <= N



// Input Format
// First Argument represents the root of binary tree A.

// Second Argument is an integer B denoting the node number.



// Output Format
// Return an integer array denoting the cousins of node B.

// NOTE: Order doesn't matter.



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

//  [6, 7]
// Output 2:

//  []


// Example Explanation
// Explanation 1:

//  Cousins of Node 5 are Node 6 and 7 so we will return [6, 7]
//  Remember Node 4 is sibling of Node 5 and do not need to return this.


vector<int> Solution::solve(TreeNode* A, int B) {
queue<pair<TreeNode*,int>>q;
q.push({A,0});
vector<int> ans;
int reqDepth=-1;
int depth;
while(!q.empty()){
    TreeNode* temp = q.front().first;
    depth=q.front().second;
    
    if(depth==reqDepth)break;
    
    q.pop();
    if((temp->left!=NULL and temp->left->val==B) || (temp->right!=NULL and temp->right->val==B)){
        reqDepth=depth+1;
        continue;
    }
    else{
       if(temp->left) q.push({temp->left,depth+1});
        if(temp->right)q.push({temp->right,depth+1});
    }
}

while(!q.empty()){
    ans.push_back(q.front().first->val);
    q.pop();
}
return ans;
}