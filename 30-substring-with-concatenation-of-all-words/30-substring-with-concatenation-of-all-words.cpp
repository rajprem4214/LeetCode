class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length();
        
        int wordSize = words[0].length();
        
        vector<int> ans;
        
        if(n<wordSize*words.size())
            return ans;
        
        unordered_map<string, int> hash;
        
        for(int i = 0; i<=n-wordSize*words.size(); i++){
            for(int k = 0; k<words.size(); k++)
                hash[words[k]] = 0;
            
            for(int k = 0; k<words.size(); k++)
                hash[words[k]]++;
            
            string temp = s.substr(i,wordSize*words.size());
             //cout<<temp<<" ";
            
            for(int j = 0; j<=temp.size() - wordSize; j+=wordSize){
                string tempSub = temp.substr(j,wordSize);
                //cout<<tempSub<<endl;
                
                if(hash.find(tempSub) == hash.end() || hash[tempSub] == 0){
                    continue;
                }
                else{
                    hash[tempSub]--;
                }
            }
            int flag = 0;
            for(int k = 0; k<words.size(); k++){
                if(hash[words[k]] != 0){
                    flag = 1;
                }
            }
            if(flag == 0)
                ans.push_back(i);
        }
        return ans;
    }
};