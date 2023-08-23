class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++) {
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto e:mp) {
            pq.push({e.second,e.first});
        }
        int idx = 0;
        while(pq.size()>1)
        {
            auto e1=pq.top();
            pq.pop();
            auto e2=pq.top();
            pq.pop();
            s[idx++]=e1.second;
            s[idx++]=e2.second;
            e1.first--;
            e2.first--;
            if(e1.first) {
                pq.push(e1);
            }
            if(e2.first) {
                pq.push(e2);
            }
        }
        
        
        if(!pq.empty()) {
            if(pq.top().first>1) {
                return "";
            }
            s[idx++]=pq.top().second;
        }
        return s;
        
    }
};