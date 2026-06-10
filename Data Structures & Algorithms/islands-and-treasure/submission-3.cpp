class Solution {
    int directions[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        size_t rows = grid.size(), cols = grid[0].size();

        function<bool(int,int)> isValid = [&](int row, int col) -> bool {
            return row >= 0 && row < rows && col >= 0 && col < cols;
        };

        queue<pair<int,int>> q;

        for(int r=0; r<rows; r++)
        for(int c=0; c<cols; c++)
        if(grid[r][c] == 0) q.push({r,c});

        while(!q.empty()){
            auto [ row, col ] = q.front(); q.pop();

            for(int k=0; k<4; k++){
                int neigh_row = row + directions[k][0], neigh_col = col + directions[k][1];

                if(!isValid(neigh_row,neigh_col) || grid[neigh_row][neigh_col] != INT_MAX) continue;

                grid[neigh_row][neigh_col] = grid[row][col] + 1;
                q.push({neigh_row, neigh_col});
            }
        }
    }
};
