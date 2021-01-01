// Given the head of a linked list, remove the nth node from the end of the list and return its head.

// Follow up: Could you do this in one pass?

 

// Example 1:


// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
// Example 2:

// Input: head = [1], n = 1
// Output: []
// Example 3:

// Input: head = [1,2], n = 1
// Output: [1]
 

// Constraints:

// The number of nodes in the list is sz.
// 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            temp=temp->next;
            sz++;
        }
        if(sz==1)
        {
            if(n==1)
                 head = NULL;
            return head;
        }
        if(sz==2)
        {
            if(n==2){
                 head=head->next;
                  return head;}
            else
            {
                head->next=NULL;
                return head;
            }
        }
        if(n==1)
        {   
            ListNode* tmp=head;
            for(int i=1;i<=sz-2;i++)
            {
                tmp=tmp->next;
            }
            tmp->next=NULL;
            return head;
        }
        if(n==sz)
        {
             head=head->next;
            return head;
        }
        ListNode* tmp=head;
        for(int i=1;i<=sz-n-1;i++) tmp=tmp->next;
        ListNode* p=tmp->next;
        p=p->next;
        tmp->next=p;
        return head;
    }
};