class Solution {
public:
       void solve(int ind,vector<int>&v,vector<vector<int>>&ans,int k,int n){
            
           if(v.size() == k){
                  ans.push_back(v);
               return;
           }
            
           
           for(int i=ind;i<=n;i++){
               
               v.push_back(i);
               solve(i+1,v,ans,k,n);
               v.pop_back();
               
           }
           
       }
    
    
    
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int>v;
        
        solve(1,v,ans,k,n);
        return ans;
    }
};