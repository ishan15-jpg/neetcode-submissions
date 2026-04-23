class Solution {
    int help(int i, int m, int j, int n, vector<vector<int>>& dp){
        if(i == m || j == n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(i == m-1 && j == n-1) return 1;

        return dp[i][j] = help(i+1,m,j,n,dp) + help(i,m,j+1,n,dp);
    }

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return help(0,m,0,n,dp);
    }
};
