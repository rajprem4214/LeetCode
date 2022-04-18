class Solution {
    // store values of bst in sorted order
    vector<int> result;
    
    // inorder traversal to get values in sorted order
    void getinorder(TreeNode *root){
        if(root==nullptr) return;
        getinorder(root->left);
        result.push_back(root->val);
        getinorder(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        getinorder(root);
        
        // return the value at k position in sorted array
        return result[k-1];
    }
};