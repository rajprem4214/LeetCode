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
    int cnt = 0;
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next != NULL) head->next = removeNthFromEnd(head->next, n);
        if(++cnt == n) return head->next;
        return head;
    }
};