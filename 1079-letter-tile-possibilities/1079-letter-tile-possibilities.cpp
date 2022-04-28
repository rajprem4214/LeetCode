class Solution {
public:
    set<string>ans;
    map<int,int>m;
    void solve(string tiles, string s)
    {
        for(int i=0;i<tiles.size();i++)
        {
            if(m[i] != 1)
            {
                m[i] = 1;
                s.push_back(tiles[i]);
                ans.insert(s);
                solve(tiles,s);
                m[i] = 0;
                s.pop_back();
            }
        }
    }
    int numTilePossibilities(string tiles) 
    {
        string s = "";
        solve(tiles,s);
        for(auto x:ans)
        {
            cout << x << " ";
        }
        return ans.size();
    }
};