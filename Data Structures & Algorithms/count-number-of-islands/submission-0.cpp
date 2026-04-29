class Solution {
    int rows[4] = {1,0,-1,0};
    int cols[4] = {0,1,0,-1};

    bool isValid(int row, int col, int rows, int cols){
        return row >= 0 && row < rows && col >= 0 && col < cols;
    }

    void help(int i, int j, int m, int n, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        visited[i][j] = true;

        for(int k=0; k<4; k++)
        if(isValid(i+rows[k],j+cols[k],m,n) && grid[i+rows[k]][j+cols[k]] == '1' && !visited[i+rows[k]][j+cols[k]])
        help(i+rows[k], j+cols[k], m, n, grid, visited);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        size_t m = grid.size(), n = grid[0].size();

        if(m == 1 && n == 1) return grid[0][0] == '1' ? 1 : 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 0;

        for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
        if(grid[i][j] == '1' && !visited[i][j]){
            help(i,j,m,n,grid,visited);
            count++;
        }

        return count;  
    }
};
