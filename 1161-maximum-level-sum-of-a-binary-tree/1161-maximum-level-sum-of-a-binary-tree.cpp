class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int level = 0, maxSum=INT_MIN, minLevel=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            level++;
            int sum = 0;
            int size = q.size();
            while(size--){
                TreeNode* cur = q.front(); 
                q.pop();
                sum += cur->val;
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            if(sum > maxSum){
                maxSum = sum;
                minLevel = level;
            }
        }
        return minLevel;
    }
};