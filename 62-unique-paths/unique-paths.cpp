class Solution {
public:
    int backtrack(int m, int n, int row, int col, vector<vector<int>>& dp)
    {
        if(row<0 || col<0 || row>=m || col>=n) return 0;
        if(row==0 && col==0) return 1;
        if(dp[row][col] != -1) return dp[row][col];

        int right = backtrack(m, n, row, col-1, dp);
        int down = backtrack(m, n, row-1, col, dp);

        return dp[row][col] = right+down;
    }
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return backtrack(m, n, m-1, n-1, dp);
    }
};