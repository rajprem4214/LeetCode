class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto it:nums)
            m[it]++;
        
        nums.clear();
        for(int i=0;i<m[0];i++)
            nums.push_back(0);
        
        for(int i=0;i<m[1];i++)
            nums.push_back(1);
        
        for(int i=0;i<m[2];i++)
            nums.push_back(2);
        
    }
};