// Given a linked list, remove the nth node from the end of list and return its head.

// For example,
// Given linked list: 1->2->3->4->5, and n = 2.
// After removing the second node from the end, the linked list becomes 1->2->3->5.

//  Note:
// If n is greater than the size of the list, remove the first node of the list.
// Try doing it using constant additional space.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    ListNode *prev=A,*st=A,*end=A;
    int temp=B-1;
    while(B!=0 && end!=NULL){
        end=end->next;B--;
    }
    if(end==NULL){
        A=A->next;
        return A;
    }
    st=st->next;end=end->next;
    while(end!=NULL){
        prev=prev->next;
        end=end->next;
        st=st->next;
    }
    if(st!=NULL)
    prev->next=st->next;
    else
     prev->next=NULL;
    return A;
    
}
