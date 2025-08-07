class Solution {
public:
    int backtrack(string& text1, string& text2, int n, int m, vector<vector<int>>& dp)
    {
        if(n < 0 || m < 0) return 0;

        if(dp[n][m] != -1) return dp[n][m];

        if(text1[n] == text2[m])
            return dp[n][m] = 1 + backtrack(text1, text2, n-1, m-1, dp);
        
        return dp[n][m] = max(backtrack(text1, text2, n-1, m, dp), backtrack(text1, text2, n, m-1, dp));
    }
    int longestCommonSubsequence(string text1, string text2) 
    {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return backtrack(text1, text2, n-1, m-1, dp);
    }
};