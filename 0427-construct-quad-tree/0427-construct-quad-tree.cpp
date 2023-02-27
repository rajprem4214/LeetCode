class Solution {
public:
    Node* construct(vector<vector<int>>& grid, int i, int j, int l) {
        bool allIsWell = true;
        for(int a=i; a<i+l; a++) 
            for(int b=j; b<j+l; b++) 
                if(grid[a][b] != grid[i][j]){
                    allIsWell = false;
                    break;
                }
        return allIsWell ? 
                new Node(grid[i][j], true, NULL, NULL, NULL, NULL) : 
                new Node(grid[i][j], false, construct(grid, i, j, l/2), 
                                            construct(grid, i, j+l/2, l/2), 
                                            construct(grid, i+l/2, j, l/2), 
                                            construct(grid, i+l/2, j+l/2, l/2));
    }
    Node* construct(vector<vector<int>>& grid) {
        return construct(grid, 0, 0, grid.size());
    }
};