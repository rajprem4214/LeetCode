class Solution {
public:
string s1="",s2="";
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        solve(root1);
        solved(root2);
        if(s1==s2)
        return true;
        return false;
    }
    void solve(TreeNode* r1)
    {
        if(r1->left==NULL&&r1->right==NULL){
        s1+=(r1->val)+'0';
        return;
        }
        else if(r1->left==NULL&&r1->right!=NULL)
        {
            solve(r1->right);
        }
        else if(r1->left!=NULL&&r1->right==NULL)
        {
            solve(r1->left);
        }
        else{
        solve(r1->left);
         solve(r1->right);
        }
    }
    void solved(TreeNode* r2)
    {
        if(r2->left==NULL&&r2->right==NULL){
        s2+=(r2->val)+'0';
        return;
        }
        else if(r2->left==NULL&&r2->right!=NULL)
        {
            solved(r2->right);
        }
        else if(r2->left!=NULL&&r2->right==NULL){
            solved(r2->left);
        }
        else{
        solved(r2->left);
         solved(r2->right);
        }
    }
};