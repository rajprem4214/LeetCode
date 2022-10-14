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
    ListNode* deleteMiddle(ListNode* head) {
   if(head==NULL)
            return head;
        if(head->next==NULL)
            return NULL;
        ListNode* slow=head, *fast=head,*prev=head;
        while(fast!=NULL && fast->next!=NULL)           // find out the middle node
        {
            prev = slow;                    // use to restore the node just before the middle node of list
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;    // linking the linked list by removing middle node
        delete slow;      // delete the middle 
        return head;  
        
    }
};