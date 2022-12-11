class Solution {
public:
    int sum=INT_MIN;
    int maxPathSum(TreeNode* root) {
        calculateMaxPath(root);
        return sum;
    }
    int calculateMaxPath(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftsum=max(0,calculateMaxPath(root->left));
        int rightsum=max(0,calculateMaxPath(root->right));
        sum=max(sum,leftsum+rightsum+root->val);
        return max(leftsum,rightsum)+root->val;
    }
};