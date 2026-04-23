class Solution {
public:
    int rob(vector<int>& nums) {
        size_t n = nums.size();
        vector<int> dp(n+1, INT_MIN);

        for(int i=n-1; i>=0; i--){
            int rob = i+2 <= n-1 ? dp[i+2] + nums[i] : nums[i];
            int noRob = i+1 <= n-1 ? dp[i+1] : 0;

            dp[i] = max(rob, noRob); 
        }

        return dp[0];
    }
};
