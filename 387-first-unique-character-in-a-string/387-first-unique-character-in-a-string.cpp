class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>m;
    for(int i=0;i<s.length();i++)
    {
        m[s[i]]++;
    }
        int ans = INT_MAX;
        for(int i=0;i<s.length();i++){
            if(m[s[i]]==1)
            {
                ans=i;
                break;
            }
            
                
        }
        if(ans==INT_MAX)
            return -1;
        else
        return ans;
    }
};