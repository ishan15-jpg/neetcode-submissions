class Solution {
    int help(int i, int n, vector<int>& cost, vector<int>& dp){
        if(i > n) return INT_MAX;
        if(dp[i] != -1) return dp[i];
        if(i == n) return 0;

        int one = help(i+1, n, cost, dp);
        int two = help(i+2, n, cost, dp);

        return dp[i] = min(one, two) + cost[i];
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        size_t n = cost.size();
        vector<int> dp(n+1, -1);
        return min(help(0,n,cost,dp), help(1,n,cost,dp));
    }
};
