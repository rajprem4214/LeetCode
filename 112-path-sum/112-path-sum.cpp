class Solution {
public:
    bool sumPath(TreeNode* root, int pathSum, int target) {
        if(root == NULL) return false;
        if(!root->left && !root->right) {
            pathSum += root->val;
            return pathSum == target;
        }
        pathSum += root->val;
        if(sumPath(root->left, pathSum, target)) return true;
        if(sumPath(root->right, pathSum, target)) return true;
        pathSum -= root->val;
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return sumPath(root, 0, targetSum);
    }
};