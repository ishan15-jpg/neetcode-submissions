class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        size_t n = cost.size();
        vector<int> dp(n+1, INT_MAX);

        dp[n] = 0;

        for(int i=n-1; i>=0; i--){
            int one = dp[i+1];
            int two = INT_MAX;
            if(i+2 <= n) two = dp[i+2];
            dp[i] = min(one, two) + cost[i];
        }

        return min(dp[0], dp[1]);
    }
};
