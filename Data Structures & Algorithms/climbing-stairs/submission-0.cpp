class Solution {
    int help(int i, int n, vector<int>& dp){
        if(i > n) return 0;
        if(dp[i] != -1) return dp[i];
        if(i == n) return 1;

        return dp[i] = help(i+1,n,dp) + help(i+2,n,dp);
    }

public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return help(0,n,dp);
    }
};
