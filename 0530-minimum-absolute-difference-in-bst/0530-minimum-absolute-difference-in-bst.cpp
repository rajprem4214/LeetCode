class Solution {
public:
    // Inorder traversal of BST gives sorted array, so inorder 
    // traversal and calculate the diff between adjacent values and  
    // keep the track of minimum diff calculated so far.Just return
    // that maintained minimum value
    
    int min_diff=INT_MAX;
    int val=-1;
    int getMinimumDifference(TreeNode* root) {
        
        if(root->left!=nullptr)
            getMinimumDifference(root->left);
        //doing this because we dont want to use initial val -1
        if(val>-1)min_diff=min(min_diff,abs(val-root->val));
        val=root->val;
        if(root->right!=nullptr)
            getMinimumDifference(root->right);
        return min_diff;
    }
};