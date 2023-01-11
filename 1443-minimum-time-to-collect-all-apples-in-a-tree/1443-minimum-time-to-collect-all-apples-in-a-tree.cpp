class Solution {
public:
vector<vector<int>> a;
vector<int> v;
int cnt;
bool ok;
    void dfs(int i,vector<bool>& hasApple,int &n,int & sum)
    {
        v[i]=1;
        for(auto k : a[i])
        {
            if(!v[k])
            {
                if(hasApple[k]==true)
                {
                    ok=1;
                    cnt=cnt+sum+1;
                    cout << sum << " ";
                }
                if(ok)
                {
                    ok=0;
                    sum=0;
                    dfs(k,hasApple,n,sum);
                }
                else
                {
                    sum++;
                    dfs(k,hasApple,n,sum);
                }
            }
        }
        sum=max(0,sum-1);
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
    {
        a.resize(n+1);
        v.resize(n+1);
        for(auto adj : edges)
        {
            a[adj[0]].push_back(adj[1]);
            a[adj[1]].push_back(adj[0]);
        }
        int sum=0;
        dfs(0,hasApple,n,sum);
        return cnt*2;
    }
};