class Solution {
    vector<int> v;
public:
    void inorder(TreeNode* root) {
        if(!root)
            return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        //find inorder traversal of the tree
        inorder(root);
        int l=0, r=v.size()-1,s;

        //using 2 pointer approach to find if a pair exists such that its total==k
        while(l<r) {
            s = v[l]+v[r];
            if(s == k)
                return true;
            if(s < k)
                l++;
            else
                r--;
        }

        return false;
    }
};