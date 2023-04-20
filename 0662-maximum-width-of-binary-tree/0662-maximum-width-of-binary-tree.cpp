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
    int widthOfBinaryTree(TreeNode* root) {
          if (root == NULL) return 0;
       int maxwidth = 1;
       queue<pair<TreeNode*,int>> q;
       q.push(make_pair(root,0));

       while(!q.empty()){
           int size = q.size();
           //Get left most inserted nodes index.
           int left = q.front().second;
           //Get right most inserted nodes index.
           int right = q.back().second;

           //width is the distance between left and right index for 
           // that level.
           maxwidth = max(maxwidth,right-left+1);

           for(int i = 0; i < size; i++){
               pair<TreeNode*,int> p = q.front();
               q.pop();
               TreeNode* temp = p.first;
                //Will work without subtracting left too.
                //But it saves computation.
               long long int index = p.second - left;

               if(temp->left){
                   q.push({temp->left,2 * index + 1});
               }
               if(temp->right){
                   q.push({temp->right, 2 * index + 2});
               }
           }
       }
    return maxwidth;
    }
};