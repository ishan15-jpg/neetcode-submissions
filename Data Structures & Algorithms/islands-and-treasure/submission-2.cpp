class Solution {
    int directions[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        size_t rows = grid.size(), cols = grid[0].size();

        function<bool(int,int)> isValid = [&](int row, int col) -> bool {
            return row >= 0 && row < rows && col >= 0 && col < cols;
        };

        function<int(int,int)> bfs = [&](int row, int col) -> int {
            vector<vector<bool>> visited(rows, vector<bool>(cols, false));
            
            queue<pair<int,int>> q;
            visited[row][col] = true;
            q.push({row,col});

            int steps = 0;
            while(!q.empty()){
                int s = q.size();
                
                for(int i=0; i<s; i++){
                    int curr_row = q.front().first, curr_col = q.front().second;
                    q.pop();

                    if(grid[curr_row][curr_col] == 0) return steps;

                    for(int k=0; k<4; k++){
                        int neigh_row = curr_row + directions[k][0], neigh_col = curr_col + directions[k][1];

                        if(isValid(neigh_row,neigh_col) && !visited[neigh_row][neigh_col]){
                            if(grid[neigh_row][neigh_col] == -1) continue;

                            visited[neigh_row][neigh_col] = true;
                            q.push({neigh_row,neigh_col});
                        }
                    }

                }

                steps++;
            }

            return INT_MAX;
        };

        for(int r=0; r<rows; r++)
        for(int c=0; c<cols; c++)
        if(grid[r][c] == INT_MAX) grid[r][c] = bfs(r,c);
    }
};
