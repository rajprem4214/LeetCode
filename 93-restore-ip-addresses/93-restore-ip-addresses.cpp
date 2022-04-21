class Solution {
public:
    vector<string> ans;
    int n;
    string num;
    void solve(string &s,string tmp,int idx,int dots)
    {
        if(dots>3)
            return;
        if(dots==3 and idx<n)
        {
           num = s.substr(idx);
           if(num!="" and stoll(num)<=255)
           {
               if(num[0]=='0' and num.size()>1)
                   return;
               tmp += num;
               ans.push_back(tmp);
           }
            return;
        }
        if(s[idx]=='0')
        {
            solve(s,tmp + s[idx] + '.',idx+1,dots+1);
        }
        else
        {
            for(int i = idx;i<idx+3 and i<n;i++)
            {
                 num = s.substr(idx,i-idx+1);
                 if(stoll(num)<=255)
                    solve(s,tmp+num +".",i+1,dots+1);
            }
        }
        
    }
    vector<string> restoreIpAddresses(string s) {
        n = s.size();
        solve(s,"",0,0);
        return ans;
    }
};