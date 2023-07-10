class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) 
            return 0;

        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            depth++;
            for (int i = 0; i < size; i++) {
                TreeNode* cur = q.front(); 
                q.pop();
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
                if (cur->left == NULL && cur->right == NULL) {
                    return depth;
                }
            }
        }
        return depth;
    }
};