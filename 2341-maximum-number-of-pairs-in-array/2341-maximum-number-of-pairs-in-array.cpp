class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        
        int a=0,b=0;
        for(auto x:m)
        {
            if(x.second%2)
            {
               a+=x.second/2;
                b+=x.second%2;  
            }
               
            else
             a+=x.second/2;   
                 
            }   
        vector<int> res;
        res.push_back(a);
        res.push_back(b);
        
        return res;
        
    }
};