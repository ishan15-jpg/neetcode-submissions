class Solution {
    int rows[4] = {1,0,-1,0};
    int cols[4] = {0,1,0,-1};

    bool isValid(int row, int col, int rows, int cols){
        return row >= 0 && row < rows && col >= 0 && col < cols;
    }

    int help(int i, int j,int m, int n,vector<vector<int>>& grid, vector<vector<bool>>& visited){
        visited[i][j] = true;

        int area = 1;
        for(int k=0; k<4; k++){
            int row = i+rows[k], col = j+cols[k];
            if(isValid(row,col,m,n) && grid[row][col] == 1 && !visited[row][col])
                area += help(row,col,m,n,grid,visited);
        }

        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        size_t m = grid.size(), n = grid[0].size();

        if(m == 1 && n == 1) return grid[0][0] == 1 ? 1 : 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int area = 0;
        
        for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
        if(grid[i][j] == 1 && !visited[i][j]) 
            area = max(area, help(i,j,m,n,grid,visited));

        return area;
    }
};
