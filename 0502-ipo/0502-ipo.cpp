class Solution {
public:
    static bool comp(pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = capital.size();
        vector<pair<int,int>> net;
        for(int i=0;i<n;i++) net.push_back({profits[i],capital[i]});
        sort(net.begin(), net.end(), comp);
        priority_queue<int> pq;
        long long ans = w;
        int i = 0;
        while(i < n){
            while(!pq.empty() && ans < net[i].second && k) {
                ans += pq.top(); pq.pop();
                k--;
            }
            if(k == 0 || ans < net[i].second) break;
            pq.push(net[i].first);
            i++;
        }
        while(k-- && !pq.empty()) {ans += pq.top(); pq.pop();}
        return ans;
    }
};