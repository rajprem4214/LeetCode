class Solution {
public:
    int pairSum(ListNode* head) {
     
        int maxi=0;
        ListNode* slow=head,*fast=head->next;
       
        while(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
            if(fast!=NULL)
                fast=fast->next;
        }
        ListNode* prev=NULL,*curr=slow;
        slow=slow->next;
         while(slow!=NULL){
             curr->next=prev;
             prev=curr;
             curr=slow;
             slow=slow->next;
         }
        curr->next=prev;
        slow=curr;
        
        while(slow!=NULL){
            maxi=max(maxi,head->val + slow->val);
            head=head->next;
            slow=slow->next;
        }
        return maxi;
    }
};