class disjointset{
    public:
    vector<int> parent, size, rank;
    disjointset(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0; i<n; i++){
            size[i]=1;
            parent[i]=i;
        }
    }

    int findupar(int node){
        if(node==parent[node])
        return node;
        return parent[node] = findupar(parent[node]); 
    }

    bool unionbysize(int u, int v){
        int uu = findupar(u);
        int uv = findupar(v);
        if(uu == uv)
            return false;
        if(size[uu]<size[uv]){
            parent[uu] = uv;
            size[uv]+=size[uu];
        }
        else{
            parent[uv] = uu;
            size[uu]+=size[uv];
        }
        return true;
    }
};

class Solution {
public:

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), [&](auto const &a, auto const &b){
            return a[0]>b[0];
        });
        disjointset alice(n+1);
        disjointset bob(n+1);

        int removededges = 0;
        int aliceedges = 0;
        int bobedges = 0;
        for(auto i:edges){
            if(i[0]==3){
                if(alice.unionbysize(i[1], i[2])){
                    bob.unionbysize(i[1], i[2]);
                    aliceedges++;
                    bobedges++;
                }
                else{
                    removededges++;
                }
            }
            else if(i[0]==1){
                if(alice.unionbysize(i[1], i[2])){
                    aliceedges++;
                }
                else{
                    removededges++;
                }
            }
            else{
                if(bob.unionbysize(i[1], i[2])){
                    bobedges++;
                }
                else{
                    removededges++;
                }
            }
        }
        if(bobedges==n-1 && aliceedges==n-1)
            return removededges;
        else
            return -1;
    }
};

