// Problem Description

// Given a linked list A , reverse the order of all nodes at even positions.



// Problem Constraints
// 1 <= Size of linked list <= 100000



// Input Format
// First and only argument is the head of the Linked-List A.



// Output Format
// Return the head of the new linked list.



// Example Input
// Input 1:

// A = 1 -> 2 -> 3 -> 4
// Input 2:

// A = 1 -> 2 -> 3


// Example Output
// Output 1:

//  1 -> 4 -> 3 -> 2
// Output 2:

//  1 -> 2 -> 3


// Example Explanation
// Explanation 1:

// Nodes are positions 2 and 4 have been swapped.
// Explanation 2:

// No swapping neccassary here.

// Pranav Singhal (IIIT-Allahabad)
// Recursive solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 void fun(ListNode* &sl,ListNode *pf,ListNode *f){    // sl if the pointer to start, pf is pointer previous to even node, f is pointer to even node
     if(f==NULL){
         return;
     }
     if(f->next!=NULL && f->next->next!=NULL){
         fun(sl,pf->next->next,f->next->next);
     }
     if(sl==pf) return ;
     ListNode *t1=sl->next->next;   // making swaps
     ListNode *t2 = sl->next;
     ListNode *t3 = f->next;
     sl->next=f;
     f->next=t1;
     pf->next=t2;
     t2->next=t3;
     sl=sl->next->next;
     if(sl==pf) return;
 }
ListNode* Solution::solve(ListNode* A) {
    ListNode *slow=A,*fast=A,*prev=A;
    if(A->next==NULL) return A;
    int c=0;
    // slow and fast method to find the mid of linked list
    while(fast!=NULL && fast->next!=NULL){  // find mid
        prev=slow;
        slow=slow->next;fast=fast->next->next;
        c++; // to check at which index the middle node lies
    }
    ListNode *head=A;
    if(c%2==1){  // check if mid is at even place or not
        fun(head,prev,slow);  // we would send the first even node after middle of the list
    }
    else{
        prev=prev->next,slow=slow->next;
        fun(head,prev,slow);
    }
    return A;
}
