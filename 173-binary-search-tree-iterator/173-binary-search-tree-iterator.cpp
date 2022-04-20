class BSTIterator {
public:
    vector<int> ans;
    int pos;
    void inorder(TreeNode *root)
    {
        if(root==NULL) return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    
    
    
    BSTIterator(TreeNode* root) {
    pos=0;
        inorder(root);
    }
    
    int next() {
        return ans[pos++];
    }
    
    bool hasNext() {
        return ans.size()!=pos;
    }
};