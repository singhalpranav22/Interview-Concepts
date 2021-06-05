// Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

// For example,
// Given 1->2->3->3->4->4->5, return 1->2->5.
// Given 1->1->1->2->3, return 2->3.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* head) {
    if(head->next==NULL) return head;
    ListNode *prev=head,*temp=head->next;
    ListNode *ans=NULL,*apt=NULL;
    bool f=false;
    while(temp!=NULL){
        if(temp->val==prev->val){
            f=true;
            prev=temp;
            temp=temp->next;
        }
        else
        {
            if(f==false){
                if(ans==NULL){
                    ans=prev;
                    apt=prev;
                }
                else{
                    apt->next=prev;
                    apt=apt->next;
                }
            }
            f=false;
            prev=temp;
            temp=temp->next;
        }
    }

    if(apt!=NULL)
    {
        if(apt->val!=prev->val && f==false) apt->next=prev,apt=apt->next;
    apt->next=NULL;
    }
    return ans;
}
