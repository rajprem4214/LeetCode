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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
//         // ListNode* ans;
        
//         while(temp != nullptr && temp->next != nullptr)
//         {
//             if(temp->val == temp->next->val)
//             {
//                 ListNode* duplicate = temp->next;
//                 temp->next = duplicate->next;
//                 delete duplicate;
//             }
//             temp = temp->next;
//         }
//         return head;
        ListNode* ans;
        set<int> s;
        while(temp != nullptr)
        {
            s.insert(temp->val);
            temp = temp->next;
        }
        ListNode* node = new ListNode();
        temp = node;
        for(auto it:s)
        {
            ListNode* node1 = new ListNode(it);
            temp->next = node1;
            temp = temp->next;
        }
        return node->next;
    }
};