class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
     int *arr=new int[n]();
        vector<int>ans;
        for(int i=0;i<edges.size();i++){
            arr[edges[i][1]]=1;
        }

        for(int i=0;i<n;i++){
            if(arr[i]==0){
                ans.push_back(i);
            }
        }
        return ans;   
    }
};