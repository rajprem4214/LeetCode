#define vb vector<bool>
#define vi vector<int> 
#define vvi vector<vi>

class Solution {
public:
    void helper (vvi &stones, int vertex, vb &visited){
        if (visited[vertex]) return;
        
        visited[vertex] = 1;
		
        for (int i = 0; i < stones.size(); i++){
            if (i != vertex && (stones[vertex][0] == stones[i][0] || stones[vertex][1] == stones[i][1])){
                helper (stones, i, visited);
            }
        }
        
        return;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size(), count = 0;        
        vb visited (n, 0);
        
        for (int i = 0; i < n; i++){
            if (visited[i] == 0) count++, helper (stones,i,visited);
        }
        
        return n-count;
    }
};