// Merge two sorted linked lists and return it as a new list.
// The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

// For example, given following linked lists :

//   5 -> 8 -> 20 
//   4 -> 11 -> 15
// The merged list should be :

// 4 -> 5 -> 8 -> 11 -> 15 -> 20

ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    if(A==NULL) return B;
    if(B==NULL) return A;
    if(A->val <= B->val)
     {
         A->next = mergeTwoLists(A->next,B);
         return A;
     }
     else{
         B->next = mergeTwoLists(A,B->next);
         return B;
     }
}