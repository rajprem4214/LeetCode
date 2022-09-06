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
    bool nozero(TreeNode* root){
        if(root==NULL) return false;
        
        bool l1 = nozero(root->left);
        bool l2 = nozero(root->right);
        
        if(!l1) root->left= NULL;
        if(!l2) root->right= NULL;
        
        if(l1==false and l2==false and root->val==0) return false;
        return true;  
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        
        // if(root==NULL or (root->left==NULL and root->right==NULL)) return root;
        
        bool res = nozero(root);
        if(res==false) return NULL;
        
        return root;
    }
};