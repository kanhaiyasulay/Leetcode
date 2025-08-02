class Solution {
public:
    int backtrack(int row, int col, vector<vector<int>>& dp)
    {
        if(row < 0 || col < 0) return 0;
        if(row == 0 && col == 0) return 1;
        
        if(dp[row][col] != -1) return dp[row][col];

        int right = backtrack(row, col-1, dp);
        int down = backtrack(row-1, col, dp);

        return dp[row][col] = (right + down);
    }
    int uniquePaths(int m, int n) 
    {
        // m -> row      n -> col
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0; i<n; i++) dp[0][i] = 1;
        for(int i=0; i<m; i++) dp[i][0] = 1;

        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                int right = dp[i][j-1];
                int down = dp[i-1][j];

                dp[i][j] = right + down;
            }
        }

        return dp[m-1][n-1];
    }
};