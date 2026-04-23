class Solution {
public:
    int rob(vector<int>& nums) {
        size_t n = nums.size();
        int next2 = 0, next1 = 0;

        for(int i=n-1; i>=0; i--){
            int rob = i+2 <= n-1 ? next2 + nums[i] : nums[i];
            int noRob = i+1 <= n-1 ? next1 : 0;

            int curr = max(rob, noRob);

            next2 = next1;
            next1 = curr;
        }

        return next1;
    }
};
