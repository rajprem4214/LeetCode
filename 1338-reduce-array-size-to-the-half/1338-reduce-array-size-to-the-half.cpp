class Solution {
public:
    int minSetSize(vector<int>& arr) {
         unordered_map<int,int> mymap;
        for(int i=0;i<arr.size();i++){
            mymap[arr[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto j:mymap){
            pq.push({j.second,j.first});
        }
        int removed=0,ans=0;
        while(removed<arr.size()/2)
        {
            removed+=pq.top().first;
            pq.pop();
            ans++;
        }
        return ans;
        
    }
};