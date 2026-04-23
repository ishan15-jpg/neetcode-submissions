class Solution {

public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);

        dp[n] = 1;

        for(int i=n-1; i>=0; --i){
            int steps = 0;
            if(i+1 <= n) steps += dp[i+1];
            if(i+2 <= n) steps += dp[i+2];

            dp[i] = steps;
        }

        return dp[0];
    }
};
