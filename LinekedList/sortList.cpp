// sort linked list O(nlogn)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode *l1,ListNode *l2){
        ListNode *head;
        
        if(l1==NULL) {
            head=l2;
            return head;
        }
        if(l2==NULL) {
            head=l1;
            return head;
        }
        if(l1->val<=l2->val){
            head=l1;
            l1=l1->next;
        }
        
        else{
            head=l2;
            l2=l2->next;
        }
        ListNode* ans=head;
        while(l1!=NULL && l2!=NULL){
            if(l1->val<=l2->val){
                head->next=l1;
                head=head->next;
                l1=l1->next;
            }
            else{
                head->next=l2;
                head=head->next;
                l2=l2->next;
            }
        }
        if(l1!=NULL) head->next=l1;
        if(l2!=NULL) head->next=l2;
        return ans;
    }
    
    ListNode* mergeSort(ListNode *head){
        if(head!=NULL && head->next!=NULL){
            ListNode *slow = head,*fast=head; // find mid by slow and fast pointer
            ListNode *prev;
            while(fast!=NULL && fast->next!=NULL){
                prev=slow;
                slow=slow->next;
                fast=fast->next->next;
            }
            prev->next=NULL;
            ListNode* a=mergeSort(head);
            ListNode* b=mergeSort(slow);
            return merge(a,b);
        }
        return head;
    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};