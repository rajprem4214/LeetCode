class Solution {
public:    
    int minMutation(string start, string end, vector<string>& bank) {
        int ans = 0;
        unordered_map<string,int>mp;
        queue<string>q;
        q.push(start);
        mp[start]++;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                string s = q.front();
                q.pop();
                if(s == end) return ans;
                for(char c : "ACGT"){
                    for(int j = 0; j < 8; j++){
                        string temp = s;
                        temp[j] = c;
                        if(mp.find(temp) == mp.end() && find(bank.begin(), bank.end(), temp) != bank.end()){
                            mp[temp]++;
                            q.push(temp);
                        }
                    }
                }                
            }
            ans++;
        }
        return -1;
    }
};