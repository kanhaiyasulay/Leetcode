class Solution {
public:
    int backtrack(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& dp)
    {
        if(row < 0 || col < 0) return 1e9;
        if(row == 0 && col == 0) return grid[0][0];
        if(dp[row][col] != -1) return dp[row][col];

        int up = 1e9, left = 1e9;
        left = backtrack(grid, row, col-1, dp) + grid[row][col];
        up = backtrack(grid, row-1, col, dp) + grid[row][col];

        return dp[row][col] = min(left, up);
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int row=0; row<m; row++)
        {
            for(int col=0; col<n; col++)
            {
                if(row==0 && col==0) dp[0][0] = grid[0][0];
                else
                {
                    int left = 1e9, up = 1e9;
                    if(col-1>=0) left = dp[row][col-1] + grid[row][col];
                    if(row-1>=0) up = dp[row-1][col] + grid[row][col];

                    dp[row][col] = min(left, up);
                }
            }
        }

        return dp[m-1][n-1];
    }
};