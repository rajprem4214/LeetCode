
class Solution {
public:

    vector<vector<int>> tree;
    vector<int> subtreeAns,ans,subtreeSize;
    Solution(){
        int mx = 3 * 1e4 +1 ;
        tree.resize(mx);
        subtreeSize.resize(mx);
        ans.resize(mx);
        subtreeAns.resize(mx);
    }

    void preprocessing(int src, int par)
    {
        int numOfNodes = 1;
        int ansForSubtree = 0;
        for(int child : tree[src])
        {
            if(child != par)
            {
                preprocessing(child, src);
                numOfNodes += subtreeSize[child];
                ansForSubtree += subtreeSize[child] + subtreeAns[child];
            }
        }
        subtreeSize[src] = numOfNodes;
        subtreeAns[src] = ansForSubtree;
    }
    
    
    
    void solve(int src, int par, int par_ans, int& totalNodes)
    {
        ans[src] = subtreeAns[src] + (par_ans + (totalNodes - subtreeSize[src]));
    
        for(int child : tree[src])
        {
            if(child != par)
                solve(child, src, ans[src] - (subtreeAns[child] + subtreeSize[child]), totalNodes);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        for(auto &p : edges){
            tree[p[0]+1].push_back(p[1]+1);
            tree[p[1]+1].push_back(p[0]+1);
        }
        preprocessing(1, 0);
        solve(1, 0, 0, n);
        vector<int> v;
        for(int i=1;i<=n;i++)
            v.push_back(ans[i]);
        return v;
    }
};
