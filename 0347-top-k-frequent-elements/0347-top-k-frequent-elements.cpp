class Solution {
public:
   static bool cmp(pair<int,int>&a, pair<int,int>&b){
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // map to store it's frequency
        unordered_map<int,int> freq;
        for(auto a:nums) ++freq[a];
        
        // convert map to vector to sort them in descending order of occurance
        vector<pair<int,int>> fre;
        for(auto a:freq) fre.push_back({a.first,a.second});
        sort(fre.begin(),fre.end(),cmp);
        
        // return the first K elements of the sorted array
        vector<int> result;
        while(k--) result.push_back(fre[k].first);
        
        return result;
    }
};