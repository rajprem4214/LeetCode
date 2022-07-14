class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;
        for(int i=0;i<preorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root = construct(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
    TreeNode* construct(vector<int>&preorder, int preStart, int preEnd, vector<int> &inorder,int inStart, int inEnd, map<int,int> &mp){
        if(preStart>preEnd || inStart>inEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = mp[root->val];
        int numsLeft = inRoot-inStart;
        
        root->left = construct(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,mp);
        root->right = construct(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,mp);
        return root;
    }
};