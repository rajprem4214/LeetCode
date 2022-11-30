class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
         map<int,int> m;
        for(int i:arr){
            m[i]++;
        }
        map<int,int> check;
        for(auto i:m){
            if(check[i.second]!=0) return false;
            check[i.second]++;
        }
        return true;
    }
};