Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode *s=NULL,*ps=NULL,*g=NULL,*gs=NULL,*temp=A;
    while(temp!=NULL){
        if(temp->val<B){
            if(ps==NULL){
                ps=temp;
                s=temp;
                temp=temp->next;
                ps->next=NULL;
            }
            else{
                ps->next=temp;
                ps=temp;
                temp=temp->next;
                ps->next=NULL;
            }
        }
        else{
            if(gs==NULL){
                gs=temp;
                g=temp;
                temp=temp->next;
                 gs->next=NULL;
                
            }
            else{
                gs->next=temp;
                gs=temp;
                temp=temp->next;
                gs->next=NULL;
            }
        }
    }
    if(s==NULL) return g;
    ps->next=g;
    return s;
}
