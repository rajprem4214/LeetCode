class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            vector<int> temp;
            while(s--){
                Node* top=q.front();
                temp.push_back(top->val);
                q.pop();
                for(auto child:top->children){
                    if(child){
                        q.push(child);
                    }
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};