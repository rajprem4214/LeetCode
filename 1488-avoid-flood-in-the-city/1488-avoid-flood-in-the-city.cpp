class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
       int n=rains.size();
    
    vector<int>ans;
    
    set<int>drydays;
    
    unordered_map<int,int>lake_index;
    
    for(int i=0;i<n;i++){
        
        if(rains[i]==0){
            
            drydays.insert(i);
            
            ans.push_back(1);
            
        }
        
        else{
            
            int lake=rains[i];
            
            if(lake_index.find(lake)!=lake_index.end()){
                
                auto itr=drydays.lower_bound(lake_index[lake]);
                
                if(itr==drydays.end()){
                    return {};
                }
                
                int index=*itr;
                
                ans[index]=lake;
                
                drydays.erase(index);
                
            }
            
            ans.push_back(-1);
            
            lake_index[lake]=i;
            
        }
        
    }
    
    return ans;
    
}
};