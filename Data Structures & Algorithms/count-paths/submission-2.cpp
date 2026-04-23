class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> next(n+1, 0);

        for(int i=m-1; i>=0; --i){
            vector<int> curr(n+1, 0);
            for(int j=n-1; j>=0; --j){
                if(i == m-1 && j == n-1){
                    curr[n-1] = 1;
                    continue;
                }
                curr[j] = next[j] + curr[j+1];
            }
            next = curr;
        }

        return next[0];
    }
};
