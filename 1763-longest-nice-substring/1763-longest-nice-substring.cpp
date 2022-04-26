class Solution {
    bool ifnice(string str, int s, int e){
        set<int> ele;
        for(int i=s;i<=e;++i) ele.insert(str[i]);
        for(auto a:ele){
            if(a<91 and ele.count(a+32)==0) return false;
            else if(a>96 and ele.count(a-32)==0) return false;
        }
        return true;
    }
public:
    string longestNiceSubstring(string s) {
        int ans=0;
        string result;
        for(int i=0;i<s.size();++i)
            for(int j=i;j<s.size();++j)
                if(ifnice(s,i,j) and (j-i+1)>ans){
                        ans = j-i+1;
                        result = s.substr(i,ans);
                    }
        return result;
    }
};