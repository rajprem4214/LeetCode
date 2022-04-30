class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> m;
        
        for(int i=0;i<jewels.length();i++){
            m[jewels[i]]++;
        }
        
        int ans=0;
        
        for(int i=0;i<stones.length();i++){
            
            if(m.find(stones[i]) != m.end())
                ans++;
        }
        
        return ans;
        
    }
};