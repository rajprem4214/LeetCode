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
   TreeNode* inserttotree(TreeNode* root, int val){
        if(!root){
            TreeNode* newNode=new TreeNode(val);
            return newNode;
        }
        if(val<root->val){
            root->left=inserttotree(root->left,val);
        }
            else{
                root->right=inserttotree(root->right,val);
            }

        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return inserttotree(root,val);
        
    }
};