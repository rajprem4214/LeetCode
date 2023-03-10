class Solution 
{
public:
    //Note : head is guaranteed to be not null, so it contains at least one node.
    ListNode* HeadNode;
    Solution(ListNode* head) 
    {
       HeadNode = head;
    }
    //returns value of a random node
    int getRandom() 
    {
        int res, len = 1;
        ListNode* x = HeadNode;
        while(x){
            if(rand() % len == 0)
            {
                res = x->val;
            }
            len++;
            x = x->next;
        }
        return res;
    }
};