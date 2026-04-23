class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        size_t m = text1.length(), n = text2.length();

        if(
            (m == 1 && text2.contains(text1[0])) || 
            (n == 1 && text1.contains(text2[0]))
        ) return 1; 

        vector<int> next(n+1, 0);

        for(int i=m-1; i>=0; --i){
            vector<int> curr(n+1, 0);
            for(int j=n-1; j>=0; --j){
                if(text1[i] == text2[j]) curr[j] = 1 + next[j+1];
                else{
                    curr[j] = max(next[j], curr[j+1]);
                }
            }
            next = curr;
        }

        return next[0];
    }
};
