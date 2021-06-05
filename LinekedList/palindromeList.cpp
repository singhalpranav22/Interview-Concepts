// Find if Linked List is Palindrome or not.
// Recursive method -  no need to reverse the second half of the list:
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 bool find(ListNode* &left,ListNode* right){
     if(left==NULL || right==NULL) return true;
     bool ans=find(left,right->next);
     if(!ans) return ans;
     ans=(left->val==right->val);
     left=left->next;
     return ans;
 }
int Solution::lPalin(ListNode* A) {
    return find(A,A);
}




// Iterative : 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* head) {
    ListNode *slow=head,*fast=head,*prev=head;
    if(head->next==NULL) return 1;
    while(fast!=NULL && fast->next!=NULL){
        prev=slow;
        slow=slow->next,fast=fast->next->next;
    }
    ListNode* temp=slow;
 
    while(temp!=NULL){
        ListNode* tp=temp;
        temp=temp->next;
        tp->next=prev;
        prev=tp;
    }
    ListNode *l1=head,*l2=prev;
    do{
        if(l1->val!=l2->val) return 0;
        l1=l1->next,l2=l2->next;
    }while(l1!=slow);
    return 1;
    
}
