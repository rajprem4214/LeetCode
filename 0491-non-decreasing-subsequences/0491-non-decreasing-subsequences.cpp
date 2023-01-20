class Solution {
public:

// The Below function is the recursive way to find all possible combinations, and we are
// storing all possible combinations inside an ordered_map as keys so that repetition of
// combinations, can be removed and the after recursive process is over all keys of map (which
// are our final answer) are store in 2D 'result' vector and returned as an answer.

    void find_combinations(vector<int>& nums, map<vector<int>, int>& g_map, int n, int i, vector<int>& sub_vec)
    {
        if(i==n)
        {
            if(sub_vec.size()>=2)
            {
                g_map[sub_vec]++;
            }
            return;
        }
        
        if(nums[i]>=sub_vec[sub_vec.size()-1])
        {
            sub_vec.push_back(nums[i]);
            find_combinations(nums, g_map, n, i+1, sub_vec);
            sub_vec.pop_back();
            
        }
        
        find_combinations(nums, g_map, n, i+1, sub_vec);
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        vector<vector<int>> result;
        map<vector<int>, int> g_map;
        vector<int> sub_vec;
        int i;
        for(i=0;i<nums.size();i++)
        {
            sub_vec.push_back(nums[i]);
            find_combinations(nums, g_map, nums.size(), i+1, sub_vec);
            sub_vec.pop_back();
        }
        
        for(auto it=g_map.begin();it!=g_map.end();it++)
        {
            result.push_back(it->first);
        }
        
        return result;
    }
};