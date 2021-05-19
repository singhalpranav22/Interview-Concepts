// Floyd cycle detection Algo for O(1) space.
// Refer : https://www.youtube.com/watch?v=LUm2ABqAs1w
// 142. Linked List Cycle II
// Medium

// 4196

// 313

// Add to List

// Share
// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

// Notice that you should not modify the linked list.

 

// Example 1:


// Input: head = [3,2,0,-4], pos = 1
// Output: tail connects to node index 1
// Explanation: There is a cycle in the linked list, where tail connects to the second node.
// Example 2:


// Input: head = [1,2], pos = 0
// Output: tail connects to node index 0
// Explanation: There is a cycle in the linked list, where tail connects to the first node.
// Example 3:


// Input: head = [1], pos = -1
// Output: no cycle
// Explanation: There is no cycle in the linked list.
 

// Constraints:

// The number of the nodes in the list is in the range [0, 104].
// -105 <= Node.val <= 105
// pos is -1 or a valid index in the linked-list.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    #define ll long long
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *p=head,*q=head;
        if(q==NULL || q->next==NULL || q->next->next==NULL) return NULL;
        p=p->next;
        q=q->next->next;
        while(q!=NULL && q->next!=NULL){
            if(p==q) break;
            p=p->next;
            q=q->next->next;
            if(q==NULL) break;
        }
        if(q==NULL || q->next==NULL) return NULL;
        // Apply Floyd's Cycle detection Algorithm
        q=head;
        while(1){
            if(p==q) break;
            p=p->next;
            q=q->next;
        }
        return p;
    }
};