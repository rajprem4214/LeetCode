/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        
        flat(root);
    }
    
    void flat(TreeNode* root){
        if(root == NULL)
            return;
        
        flat(root->right);
        flat(root->left);
        
        root->right = prev;
        root->left = NULL;
        prev = root;
        
    }
};