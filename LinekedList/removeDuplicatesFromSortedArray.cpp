// Given a sorted linked list, delete all duplicates such that each element appear only once.

// For example,
// Given 1->1->2, return 1->2.
// Given 1->1->2->3->3, return 1->2->3.

ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A==NULL || A->next==NULL) return A;
    if(A->val==A->next->val){  // dont include this node
        return deleteDuplicates(A->next);
    }
    else{  // include this node
        A->next = deleteDuplicates(A->next);
        return A;
    }
}
