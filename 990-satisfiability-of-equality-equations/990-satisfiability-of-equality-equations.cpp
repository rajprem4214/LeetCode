class Solution {
    
    
    vector<vector<int>> buildGraph(vector<string>& equations){
        vector<vector<int>> graph(26);
        int m = equations.size();
        for(int i = 0 ; i < m ; i++){
            if(equations[i][1] == '='){
                int u = equations[i][0] - 'a';
                int v = equations[i][3] - 'a';
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }
        return graph;
    }
    
    void DFS(int node , vector<vector<int>> &graph , int curColor , vector<int>&colors){
        if(colors[node] != -1){
            return;
        }
        colors[node] = curColor;
        for(auto child: graph[node]){
            DFS(child , graph , curColor , colors);
        }
    }
    
    vector<int> colorGraph(vector<vector<int>> &graph){
        vector<int> colors(26 , -1);
        int curColor = 0;
        for(int i = 0 ; i < 26 ; i++){
            if(colors[i] == -1){
                DFS(i, graph, curColor, colors);
                curColor++;
            }
        }
        return colors; 
    }
    
    bool isValidColoring(vector<int> &colors , vector<string>&equations){
        int m = equations.size();
        for(int i = 0 ; i < m ; i++){
            if(equations[i][1] == '!'){
                int u = equations[i][0] - 'a';
                int v = equations[i][3] - 'a';
                if(colors[u] == colors[v]){
                    return 0;
                }
            }
        }
        return 1;
    }
    
public:
    bool equationsPossible(vector<string>& equations) {
        vector<vector<int>> graph = buildGraph(equations);
        vector<int> colors = colorGraph(graph);
        return isValidColoring(colors , equations);
    }
};