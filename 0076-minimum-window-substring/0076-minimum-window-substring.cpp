class Solution {
public:
    string minWindow(string s, string t) 
    {
        vector<int> remain(128,0);
        int required=t.size();
        for(int i=0;i<required;i++)
        {
            remain[t[i]]++;
        }
        int min=INT_MAX,start=0,min_i,i=0;
        while(i<=s.size()&&start<s.size())
        {
            if(required)
            {
                if(i==s.size()) break;
                if(remain[s[i]]>0) required--;
                remain[s[i]]--;
                i++;

            }
            else
            {
                if(i-start<min)
                {
                    min=i-start;
                    min_i=start;
                }
                remain[s[start]]++;
                if(remain[s[start]]>0) required++;
                start++;
            }
        }
        return min==INT_MAX?"":s.substr(min_i,min);

        
    }
};