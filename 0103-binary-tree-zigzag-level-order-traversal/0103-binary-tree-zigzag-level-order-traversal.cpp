class Solution {
public:

   void solve(vector<vector<int>>&res,TreeNode *root){
       
       if(root==NULL){
           return ;
       }

       bool sidha=true;

       queue<TreeNode*>q;
       q.push(root);

       while(!q.empty()){
            
            int n=q.size();
        

           if(sidha){
              
              vector<int>temp;

              for(int i=0;i<n;i++){
                   
                    TreeNode *node =q.front();
                    q.pop();

                    temp.push_back(node->val);

                    if(node->left){
                        q.push(node->left);

                        
                    }


                    if(node->right){
                              q.push(node->right);
                    }


              }

              res.push_back(temp);

              sidha=false;

           }
           else{
                vector<int>temp;
                for(int i=0;i<n;i++){

                    TreeNode *node=q.front();
                    q.pop();

                    

                    temp.push_back(node->val);


                    if(node->left)q.push(node->left);
                    if(node->right)q.push(node->right);


                }

                sidha=true;
                reverse(temp.begin(),temp.end());
                res.push_back(temp);

           }




       }
   }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

       vector<vector<int>>res;
       solve(res,root);
       return res; 
    }
};