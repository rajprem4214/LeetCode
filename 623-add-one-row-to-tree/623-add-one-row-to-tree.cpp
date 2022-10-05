class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root){return root;}
        if(depth -1 == 0){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        if(depth -1 == 1){
            TreeNode* leftNode = new TreeNode(val);
            if(root->left){
                leftNode->left = root->left;
            }
            root->left = leftNode;
            TreeNode* rightNode = new TreeNode(val);
            if(root->right){
                rightNode->right = root->right;
            }
            root->right = rightNode;
            return root;
        }
        root->left = addOneRow(root->left, val, depth -1);
        root -> right = addOneRow(root->right, val, depth -1);
        return root;
    }
};