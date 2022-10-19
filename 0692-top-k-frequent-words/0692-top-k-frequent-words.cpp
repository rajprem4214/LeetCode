class myComparator {
  public:
    bool operator() (const pair<int, string> &p1, const pair<int, string> &p2) {
      if(p1.first!=p2.first)
          return p1.first<p2.first;
        return p1.second>p2.second;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
      
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, myComparator> pq;
        
        vector<string> res;
        
        unordered_map<string, int> mp;
        
        
        for(auto word: words)
            mp[word]+=1;
        
        for(auto itr: mp){
            pq.push({itr.second, itr.first});
        }
        
        while(!pq.empty() and k>0){
            auto temp=pq.top();
            pq.pop();
            res.push_back(temp.second);
            
            k-=1;
        }
        
        // reverse(res.begin(), res.end());
        
        return res;
    }
};