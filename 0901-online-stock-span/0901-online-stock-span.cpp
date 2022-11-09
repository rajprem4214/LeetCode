class StockSpanner {
    stack<pair<int,int>> st;
public:
    StockSpanner() {
    }
	
    int next(int price) {
        if(st.empty())
        {
            st.push({price,1});
            return 1;
        }
        
        int ans = 1;
        while(!st.empty() && st.top().first<=price)
        {
            ans += st.top().second;
            st.pop();
        }
       
        st.push({price,ans});
        return ans;
    }
};