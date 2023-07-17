class Solution {
  public:
    ListNode* rev(ListNode* h) {
        ListNode* cur = h;
        ListNode* prev = NULL;
        while(cur) {
            ListNode* n = cur->next;
            cur->next = prev;
            prev = cur;
            cur = n;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* rev_list1 = rev(l1);
        ListNode* rev_list2 = rev(l2);
        ListNode* dummy = new ListNode(0);
        ListNode* tmp = dummy;
        int sum=0, rem=0;

        while(true) {
            sum = 0;
            sum += rem;
            if (rev_list1) {
              sum += rev_list1->val; 
              rev_list1 = rev_list1->next;
            }
            if (rev_list2) {
              sum += rev_list2->val; 
              rev_list2 = rev_list2->next;
            }
            rem = sum/10;
            sum = sum%10;
            tmp->next = new ListNode(sum);
            tmp = tmp->next;
            
            if(!rev_list1 && !rev_list2 && (rem == 0)) break;
        }
        return rev(dummy->next);
    }
};