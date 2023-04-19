class Solution {
public:

   int ans=0;
   void solve(TreeNode* root,bool flag,int count){
       if(!root)
       {
           ans=max(ans,count);
           return;
       }

       if(flag==0){
           solve(root->left,1,count+1); //continued zigzag path
           solve(root->right,0,1);  //starting from current pos
       }
       if(flag==1){
           solve(root->right,0,count+1);//continued zigzag path
           solve(root->left,1,1);//starting from current pos
       }
   }
    int longestZigZag(TreeNode* root) {
        solve(root,0,0);
        solve(root,1,0);
        return ans-1;
    }
};