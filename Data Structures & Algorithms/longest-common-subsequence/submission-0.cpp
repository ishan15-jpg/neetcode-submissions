class Solution {
    int help(int i, int m, string& text1, int j, int n, string& text2, vector<vector<int>>& dp){
        if(i == m || j == n) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i] == text2[j]) return dp[i][j] = 1 + help(i+1,m,text1,j+1,n,text2,dp);

        return dp[i][j] = max(help(i+1,m,text1,j,n,text2,dp), help(i,m,text1,j+1,n,text2,dp));
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        size_t m = text1.length(), n = text2.length();

        if(
            (m == 1 && text2.contains(text1[0])) || 
            (n == 1 && text1.contains(text2[0]))
        ) return 1; 

        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        return help(0,m,text1,0,n,text2,dp);
    }
};
