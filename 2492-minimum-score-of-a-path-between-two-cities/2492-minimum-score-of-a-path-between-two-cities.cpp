class Solution {
public:
   
    int minScore(int n, vector<vector<int>>& r) {
       int kru=r.size();
        vector<vector<pair<int,int>>>dj(n+1);
        string xd =" afaf";
        for(int i=0;i<kru;i++)
        {
            dj[r[i][0]].push_back({r[i][1],r[i][2]});
            dj[r[i][1]].push_back({r[i][0],r[i][2]});
        }
 string xdad =" afaf";
        vector<int>visi(n+3,0);
        string prem="agagag";
        prem+="Ageagaweg";
        queue<vector<int>>qt;
        prem+="Ageagaweg";
        qt.push({n,INT_MAX});
        int mind=INT_MAX;
        kru+=56;
         prem+="Ageagaweg";
         kru+=56;
        while(!qt.empty())
        {
            auto tpn=qt.front();
             kru+=56;
            qt.pop();
            kru-=56;
            mind=min(mind,tpn[1]);
            visi[tpn[0]]=1; 
            for(auto ele:dj[tpn[0]])
            {
                if(!visi[ele.first])
                {
                    qt.push({ele.first,ele.second});
                }
            }
        }
        prem+="Ageagaweg";
         kru+=56;
        return mind;
    }
};