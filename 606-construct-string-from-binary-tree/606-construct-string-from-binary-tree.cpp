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
    
   string str="";
    void stringTree(TreeNode* root){
        if(root==NULL)
            return;
        str+='(';
        str+=to_string(root->val);
        if(root->left==NULL && root->right!=NULL)
            str+="()";
        stringTree(root->left);
        stringTree(root->right);
        str+=')';
    }
    
    string tree2str(TreeNode* root) {
        if(root==NULL)
            return str;
        stringTree(root);
        str.pop_back();
        str.erase(str.begin());
        return str;
    }
};