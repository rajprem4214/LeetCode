class Solution {
public:
    int partitionString(string s) {
        map<char,int> m;
        int k=0;
        for(int i=0;i<s.size();i++)
        {
            if(m[s[i]]==1)
            {
               k++;
               m.clear();
            }
            m[s[i]]++;
           
        }
        return k+1;
        
    }
};