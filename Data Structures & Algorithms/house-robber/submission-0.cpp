class Solution {
    int help(int i, int n, vector<int>& nums, vector<int>& dp){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        if(i == n-1) return nums[n-1];

        int rob = nums[i] + help(i+2,n,nums,dp);
        int noRob = help(i+1,n,nums,dp);

        return dp[i] = max(rob,noRob);
    }

public:
    int rob(vector<int>& nums) {
        size_t n = nums.size();
        vector<int> dp(n+1, -1);

        return help(0,n,nums,dp);
    }
};
