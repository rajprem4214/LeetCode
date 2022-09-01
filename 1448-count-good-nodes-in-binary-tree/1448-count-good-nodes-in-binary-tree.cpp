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
    void helper(int &ans,int mx,TreeNode* root){
        if(root==NULL)
            return;
        int left = mx;
        int right = mx;
       
        if(root->left != NULL)
        {
            left = max(left,root->left->val);
            if(left == root->left->val)
                ans++;
            
            helper(ans,left,root->left);
        }
        if(root->right != NULL)
        {
            right = max(right,root->right->val);
            if(right == root->right->val)
                ans++;
            
            helper(ans,right,root->right);
        }
        return;
        
        
    }
    
    
    int goodNodes(TreeNode* root) {
       int mx = root->val;
        int ans=0;
        helper(ans,mx,root);
        return ans+1;
    }
};