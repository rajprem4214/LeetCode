class Solution {
public:
    
    void solve(TreeNode* root,vector<int>freq,int &cnt){
        if(root==NULL)
            return;
        freq[root->val]++;
        solve(root->left,freq,cnt);
        if(root->left==NULL and root->right==NULL){
            int odd =0;
            for(auto it:freq){
                if(it%2!=0)
                    odd++;
            }
            if(odd<=1){
                cnt++;
            }
        }
        solve(root->right,freq,cnt);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freq(10,0);
        int cnt = 0;
        solve(root,freq,cnt);
        return cnt;
    }
};