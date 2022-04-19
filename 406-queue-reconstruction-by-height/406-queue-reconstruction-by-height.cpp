class Solution {
public:
   static bool cmp(vector<int> &x, vector<int> &y){
        if(x[0] == y[0]){
            if(y[1] > x[1])
                return true;
        }else{
            if(x[0] > y[0])
                return true;
        }
        return false;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        
        sort(people.begin(), people.end(), cmp);
        
        for(vector<int>& x : people){
            ans.insert(ans.begin() +x[1], x);
        }
        return ans;
    }
};