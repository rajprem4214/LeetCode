class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0, j=0;
        
        unordered_map<int, int> mp;
        
        int res=0;
        
        while(j<fruits.size()){
            mp[fruits[j]]+=1;
            
            if(mp.size()<=2){
                res=max(res, j-i+1);
                
            }else {
                while(mp.size()>2){
                    mp[fruits[i]]-=1;
                    if(mp[fruits[i]]==0){
                        mp.erase(fruits[i]);
                        
                    }
                    i++;
                }
                res=max(res, j-i+1);
            }
            j++;
        }
        
        return res;
    }
};