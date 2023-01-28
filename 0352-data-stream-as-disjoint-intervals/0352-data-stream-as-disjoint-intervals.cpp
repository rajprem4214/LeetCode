class SummaryRanges {
public:
    set<int> st;

    SummaryRanges() {}
    
    void addNum(int value) {
        st.emplace(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for(auto x:st){
            if(ans.size() && ans.back().back()+1 == x) ans.back().back() = x;
            else ans.push_back({x,x});
        }
        return ans;
    }
};