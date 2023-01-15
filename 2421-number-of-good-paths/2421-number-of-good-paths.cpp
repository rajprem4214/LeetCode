class UnionFind{
private:
    vector<int> parent,rank;
public:
    
    UnionFind(int size){
        parent.resize(size);
        rank.resize(size+1);
        for(int i = 0; i<size; i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }
    
    int Find(int x){
        return parent[x] == x ? x : parent[x] = Find(parent[x]);
    }
    
    void Union(int x, int y){
        int i = Find(x), j = Find(y);
        if(i != j){
            if(rank[i] == rank[j]) rank[i]++;
            else if(rank[i] < rank[j]) swap(i,j);
            parent[j] = i;
        }
    }
};



class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        
        vector<vector<int>> graph(n);
        for(auto edge : edges){
            int u = edge[0], v = edge[1];
            if(vals[u] >= vals[v]) graph[u].push_back(v);
            if(vals[u] <= vals[v]) graph[v].push_back(u);
        }
        
        map<int,vector<int>> mp;
        for(int i = 0; i<n; i++) mp[vals[i]].push_back(i);
        
        UnionFind uf(n);
        int ans = 0;
        
        for(auto it : mp){
            
            for(int node : it.second)
                for(int nbr : graph[node]) uf.Union(nbr,node);
            
            map<int,int> path;
            for(auto node : it.second) path[uf.Find(node)]++;
            
            ans += it.second.size();
            
            for (auto& [groupID, sz] : path)
                if (sz > 1) ans += (sz * (sz - 1)) / 2;
                 
        }
        return ans; 
    }
};