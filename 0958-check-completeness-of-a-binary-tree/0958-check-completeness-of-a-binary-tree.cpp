class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        bool pastNull = false;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode * front = q.front();
            q.pop();

            if(pastNull && front)
                return false;

            if(!front)
            {
                pastNull = true;
                continue;
            }
            else
            {
                q.push(front->left);
                q.push(front->right);
            }
        }
        return true;
    }
};