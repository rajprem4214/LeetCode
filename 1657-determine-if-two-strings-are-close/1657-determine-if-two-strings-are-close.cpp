class Solution {
public:
    bool closeStrings(string w1, string w2) {
        if(w1.size() != w2.size())
            return false;
       
        set<char>s1,s2;
         for(int i=0;i<w1.size();i++)
             s1.insert(w1[i]);
        
        for(int i=0;i<w2.size();i++)
             s2.insert(w2[i]);
        
        if(s1!=s2)
            return false;
        
        map<char,int>m1;
        map<char,int>m2;
        for(int i=0;i<w1.size();i++)
        {
            m1[w1[i]]++;
        }
        for(int i=0;i<w2.size();i++)
        {
            m2[w2[i]]++;
        }
        vector<int> v1,v2;
        for(auto it: m1)
            v1.push_back(it.second);
        
        for(auto it:m2)
            v2.push_back(it.second);
        
        sort(v1.begin(),v1.end());
         sort(v2.begin(),v2.end());
        for(auto it:v1)
            cout<<it<<endl;
        if(v1==v2)
            return true;
        else
            return false;
        
    }
};