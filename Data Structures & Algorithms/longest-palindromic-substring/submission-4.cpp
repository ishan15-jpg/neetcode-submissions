class Solution {
    bool isPalindrome(int i, int j, string s, vector<vector<int>>& dp){
        if(i >= j) return dp[i][j] = 1;
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]) return dp[i][j] = isPalindrome(i+1,j-1,s,dp);

        return dp[i][j] = 0;
    }

public:
    string longestPalindrome(string s) {
        size_t n = s.length();

        if(n == 1) return s;

        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        int maxLen = 0, sp = -1;

        for(int i=0; i<n; i++)
        for(int j=i; j<n; j++)
        if(isPalindrome(i,j,s,dp)){
            if(j-i+1 > maxLen){
                maxLen = j-i+1;
                sp = i;
            }
        }

        return s.substr(sp, maxLen);
    }
};
