class Solution {
public:
    int sumNumbers(TreeNode* root, int sum = 0) {
        if (!root) return 0;
        if (!root->left && !root->right) return sum * 10 + root->val;
        return sumNumbers(root->left, sum * 10 + root->val) + sumNumbers(root->right, sum * 10 + root->val);
    }
};