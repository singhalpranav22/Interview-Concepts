// Problem Description

// Max Heap is a special kind of complete binary tree in which for every node the value present in that node is greater than the value present in it’s children nodes.

// Find the number of distinct Max Heap can be made from A distinct integers.

// In short, you have to ensure the following properties for the max heap :

// Heap has to be a complete binary tree ( A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.)
// Every node is greater than all its children.
// NOTE: If you want to know more about Heaps, please visit this link. Return your answer modulo 109 + 7.



// Problem Constraints
// 1 <= A <= 100



// Input Format
// First and only argument is an inetegr A.



// Output Format
// Return an integer denoting the number of distinct Max Heap.



// Example Input
// Input 1:

//  A = 4
// Input 2:

//  A = 10


// Example Output
// Output 1:

//  3
// Output 2:

//  3360


// Example Explanation
// Explanation 1:

//  Let us take 1, 2, 3, 4 as our 4 distinct integers
//  Following are the 3 possible max heaps from these 4 numbers :
//       4           4                     4
//     /  \         / \                   / \ 
//    3    2   ,   2   3      and        3   1
//   /            /                     /

//  1            1                     2
// Explanation 2:

//  Number of distinct heaps possible with 10 distinct integers = 3360.

// Created By : Pranav Singhal
// IIIT-Allahabad
#define mod 1000000007
#define ll long long
ll dp[501][501];
ll t[1001];
ll bin(ll a,ll n){  // function to find a^n
    if(n==0) return 1;
    if(n%2==0){
        ll res = bin(a,n/2);
        return (res*res)%mod;
    }
    else{
        ll res = bin(a,(n-1)/2);
        ll tp = (a*res)%mod;
        return (tp*res)%mod;
    }
}
ll ncr(ll n,ll r){  // function to return nCr
    if(n==0 || r==0) return 1;
    if(n==r) return 1;
    if(r==1) return n;
    if(dp[n][r]!=-1) return dp[n][r];
    return dp[n][r]=(ncr(n-1,r)+ncr(n-1,r-1))%mod;  // by formula : nCr = n-1Cr + n-1Cr-1
}
ll find(ll n){  // finds answer for n nodes in the left and right subtree 
     if(n<=1) return 1;
     if(t[n]!=-1) return t[n];
     ll h = log2(n+1); // find height of tree
     ll l = bin(2,h-1)-1;  // number of nodes in each level except that of last for left subtree
     ll r = l; // number of nodes for right subtree (only last level may have different number of nodes in both levels)
     ll rem = n-2*l; // find remaining nodes for left level
     ll last = bin(2,h);  // number of nodes in last level if the tree was complete
     if(rem>=(last/2)){
         l+=last/2;  // put half in left
         r+= rem - (last/2); // put remaining in right
     }
     else{
         l+=rem;  // as last level nodes already greater then it's half so all the nodes go to the left subtree
     }
     ll tp = (ncr(n,l)*find(l-1))%mod;   // find answer by distributing l nodes to left subtree from the n available nodes
     return t[n]=(tp*find(r-1))%mod; // recursive call
}
int Solution::solve(int A) {
    memset(dp,-1,sizeof(dp));
    memset(t,-1,sizeof(t));
    return (int)find(A-1); // find answer for left and rightsubtrees (A-1 nodes remains)
}
