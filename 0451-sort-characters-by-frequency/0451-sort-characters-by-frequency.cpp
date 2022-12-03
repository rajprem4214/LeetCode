class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp; 
        for (char c : s) {
            mp[c]++; 
        }
        
        unordered_map<int, vector<char>> mp2; 
        vector<int> toSort; 
        for (auto it : mp) {
            mp2[it.second].push_back(it.first);
        }
        
        for (auto it : mp2) {
            toSort.push_back(it.first);
        }
        
        sort(toSort.begin(), toSort.end());
        string res = ""; 
        for (int i = toSort.size() - 1; i >= 0; i--) {
            int size = mp2[toSort[i]].size(); 
            for (int j = 0; j < mp2[toSort[i]].size(); j++) {
                string local(toSort[i], mp2[toSort[i]][j]);
                res += local; 
            }
        }
        
        return res;
    }
};