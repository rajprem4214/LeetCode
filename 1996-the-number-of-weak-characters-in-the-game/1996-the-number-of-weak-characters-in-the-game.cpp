class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& mat) {
        sort(begin(mat), end(mat), [&](auto &a, auto &b) { 
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]; });
        
        int ans = 0, gre = mat.back().back();
        
        for(int i=mat.size()-2;i>=0;i--){
            if(mat[i].back() < gre) ans++;
            gre = max(gre,mat[i].back());
        }
        
        return ans;
    }
};