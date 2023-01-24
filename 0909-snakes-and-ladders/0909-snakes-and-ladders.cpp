class Solution {
public:
    pair<int,int> intToPos(int n, int square){
        int r = (square-1) / n;
        int c = (square-1) % n;

        if(r % 2){
            c = n-1-c;
        }
        return {r, c};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        reverse(board.begin(), board.end());

        queue<pair<int,int>> q;
        q.push({1,0});   // {square, moves}
        unordered_set<int> visited;
        while(!q.empty()){
            int square = q.front().first;
            int moves = q.front().second;
            q.pop();

            for(int i=1; i<=6; i++){
                int next = square + i;
                pair<int,int> p = intToPos(n, next);
                int r = p.first, c = p.second;

                if(board[r][c] != -1){
                    next = board[r][c];
                }
                if(next == n*n){
                    return moves + 1;
                }
                if(visited.find(next) == visited.end()){
                    visited.insert(next);
                    q.push(make_pair(next, moves+1));
                }
            }
        }
        return -1;
    }
};