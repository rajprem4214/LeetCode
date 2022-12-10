class Solution {
public:
    long long  totalSum,ans;
    int solve(TreeNode *root,int flag){
        if(!root) return 0;
        long long  sum = root->val;
        sum += solve(root->left,flag);
        sum += solve(root->right,flag);
        if(flag){
             long long prod = (totalSum - sum)*sum;
             ans = max(ans,prod);
        }
        return sum;
    }
   
    int maxProduct(TreeNode* root) {
        totalSum = solve(root,false);
        ans = 0 ;
        long long  mod = 1e9+7;
        solve(root,true);

        return (ans)%mod;
        
    }
};