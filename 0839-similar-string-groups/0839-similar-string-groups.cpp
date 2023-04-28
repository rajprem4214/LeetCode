class DSU{
    vector<int> par, size;

public:
    DSU(int n){
        par.resize(n+1, -1);
        size.resize(n+1, 1);
    }

    int findPar(int u){
        return par[u] == -1 ? u : par[u] = findPar(par[u]);
    }

    bool unite(int u, int v){
        u = findPar(u), v = findPar(v);
        if(u == v) return 0;
        if(size[u] > size[v] ) swap(u, v);
        par[u] = v;
        size[v] += size[u];
        return 1;
    }
};


class Solution {
    bool isSimilar(string &s1, string &s2){
        int cntDiffer = 0;
        for(int i=0; i<s1.size(); i++){
            if( s1[i] != s2[i] ) cntDiffer++;
        }
        return cntDiffer <= 2;
    }

public:
    int numSimilarGroups(vector<string>& strs) {
        int grp = strs.size(), n = strs.size();
        DSU dsu(n);

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if( isSimilar(strs[i], strs[j]) && dsu.unite(i, j) ) grp --;
            }
        }
        return grp;
    }
};