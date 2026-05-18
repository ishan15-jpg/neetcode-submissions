class Solution {
public:
    int maxProfit(vector<int>& prices) {
        size_t n = prices.size();

        int min_ = INT_MAX, diff = 0;

        for(int i=0; i<n; i++){
            if(prices[i] < min_){
                min_ = prices[i];
            }else{
                int d = prices[i] - min_;
                diff = max(diff, d);
            }
        }

        return diff;
    }
};
