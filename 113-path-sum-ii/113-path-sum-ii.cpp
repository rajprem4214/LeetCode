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
    vector<vector<int>> ans;
    void DFS(TreeNode* root, int sum,int targetSum,vector<int> path){
        if(root == NULL){
            return;
        }
        sum+=root->val;
        path.push_back(root->val);
        if(root->left==NULL && root->right == NULL){
            if(sum == targetSum){
                ans.push_back(path);
            }
        }
        DFS(root->left,sum,targetSum,path);
        DFS(root->right,sum,targetSum,path);
        

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        DFS(root,0,targetSum,path);
        return ans;
    }
};