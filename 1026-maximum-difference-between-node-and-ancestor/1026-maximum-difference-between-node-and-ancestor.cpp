class Solution {
public:
int diff;
    void Max(TreeNode*root,TreeNode*child)
    {
        if(root==NULL || child==NULL)
        return;
        diff=max(diff,abs(root->val-child->val));
        Max(root,child->left);
        Max(root,child->right);
    }
    void rootupdate(TreeNode*root)
    {
        if(root==NULL)
        return;
        Max(root,root->left);
        Max(root,root->right);
        rootupdate(root->left);
        rootupdate(root->right);
    }
    int maxAncestorDiff(TreeNode* root) {
        rootupdate(root);
        return diff;
    }
};