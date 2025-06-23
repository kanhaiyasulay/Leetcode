class Solution {
public:
    int backtrack(vector<vector<int>>& grid, vector<vector<int>>& dp, int row, int col)
    {
        if(row == 0 && col == 0) return grid[0][0];
        if(row < 0 || col < 0) return 1e8;
        if(dp[row][col] != -1) return dp[row][col];

        int up = grid[row][col] + backtrack(grid, dp, row-1, col);
        int left = grid[row][col] + backtrack(grid, dp, row, col-1);

        return dp[row][col] = min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return backtrack(grid, dp, n-1, m-1);
    }
};
