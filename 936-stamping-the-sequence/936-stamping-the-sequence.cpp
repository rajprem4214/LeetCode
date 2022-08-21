class Solution {
public:
    string target;
    vector<int> res;
    int n;
    void dfs(string& s, string cur, vector<int>&order, int t) {
        if(t>10*n) return;
        if(cur==target) {
            res=order;
            return;
        }
        for(int i=0;i+s.size()<=n;i++) {
            bool flag=true;
            int c=0;
            for(int j=0;j<s.size();j++) {
                if(cur[i+j]==s[j]||cur[i+j]=='?') {
                    if(cur[i+j]==s[j]) c++;
                }else {
                    flag=false;
                    break;
                }
            }
            if(flag && c) {
                for(int k=i;k<i+s.size();k++)
                    cur[k]='?';
                order.push_back(i);
                dfs(s,cur,order,t+1);
                break;
            }
        }
    }
    vector<int> movesToStamp(string s, string t) {
    this->n=t.size();
    if(s[0]!=t[0] || s.back()!=t.back()) return res;
    target=string(n,'?');
    vector<int> order;
    dfs(s,t,order,0);
    if(res.size()>0) reverse(begin(res),end(res));
    return res;
    }
};