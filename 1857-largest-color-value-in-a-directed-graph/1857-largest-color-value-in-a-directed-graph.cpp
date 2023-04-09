class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        // indegree of every node to do modified BFS
        vector<int> indegrees(n,0);
        // standard adjacency list graph
        vector<vector<int>> graph(n,vector<int>());
        for(vector<int>& edge:edges){
            //making graph
            graph[edge[0]].push_back(edge[1]);
            // updating indegree
            indegrees[edge[1]]++;
        }
        queue<int> zero_indegree;
        for(int i=0;i<n;i++){
            if(indegrees[i]==0){
                zero_indegree.push(i);
            }
        }
        //every node is upto 26 diff colors
        vector<vector<int>> counts(n,vector<int>(26,0));
        for(int i=0;i<n;i++){
            //node is updated with its color
            counts[i][colors[i]-'a']++;
        }
        int maxi=0;
        int visited=0;
        while(!zero_indegree.empty()){
            int u=zero_indegree.front();
            // fetches front element
            zero_indegree.pop();
            visited++;//visit count increased
        for(int v: graph[u]){
            for(int i=0;i<26;i++){
                counts[v][i]=max(counts[v][i],counts[u][i]+(colors[v]-'a'==i?1:0));
                                                            //cheks if same color
                 
            }
            indegrees[v]--;
            if(indegrees[v]==0){
                zero_indegree.push(v);
            }
        }
        maxi=max(maxi,*max_element(counts[u].begin(),counts[u].end()));
        }
        return visited==n?maxi:-1;//loop checks with visit count
    }
};