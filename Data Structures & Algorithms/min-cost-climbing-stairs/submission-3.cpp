class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        size_t n = cost.size();
        int next1 = 0, next2 = INT_MAX;

        for(int i=n-1; i>=0; i--){
            int curr = min(next1, next2) + cost[i];

            next2 = next1;
            next1 = curr;
        }

        return min(next1,next2);
    }
};

