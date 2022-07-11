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
   
	// Recursive function
    void helper(TreeNode* root, vector<int> &ans, int i){
        if(root == NULL) return;
        
        if(i == ans.size())
            ans.push_back(root->val);
        
		// Right first DFS
        helper(root->right, ans, i+1);
        helper(root->left, ans, i+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        helper(root, ans, 0);
        return ans;
    }
};