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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt =  0;
        vector<ListNode*> res;
        while(temp != NULL)
        {
            cnt++;
            temp = temp->next;
        }
        int rem = 0;
        if(cnt > k)
            rem = (cnt/k) + (cnt%k);
        
      if(cnt < k)
      {
          int loop = k;
          ListNode* cur = head;
          while(loop > 0 && cur != NULL)
          {
              ListNode* nxt = cur->next;
              cur->next = NULL;
              res.push_back(cur);
              cur = nxt;
              loop--;
          }
          while(loop>0)
          {
              res.push_back(NULL);
              loop--;
          }
      }else{
          int remainder=cnt%k;
            int val=cnt/k;
            ListNode* curr=head;
          for(int i=0;i<remainder;i++){
                int c=0;
                ListNode* h=curr;
                ListNode* prev;
                while(c!=val+1){
                    c++;
                    prev=curr;
                    curr=curr->next;
                }
                prev->next=NULL;
                res.push_back(h);
            }
            for(int j=remainder;j<k;j++){
                int c=0;
                ListNode* h=curr;
                ListNode* prev;
                while(c!=val){
                    c++;
                    prev=curr;
                    curr=curr->next;
                }
                prev->next=NULL;
                res.push_back(h);
            }
      }
        return res;
    }
};