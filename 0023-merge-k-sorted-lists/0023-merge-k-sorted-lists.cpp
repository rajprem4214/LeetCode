class cmp{
    public:
    bool operator() (ListNode* a,ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp> q;
        ListNode* ans = new ListNode(-1);
        ListNode* tail = ans;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL)
                q.push(lists[i]);
        }
        while(q.size()){
            ListNode* temp = q.top();
            tail->next = temp;
            tail = temp;
            q.pop();
            if(temp->next!=NULL)
                q.push(temp->next);
        }
        return ans->next;
    }
};