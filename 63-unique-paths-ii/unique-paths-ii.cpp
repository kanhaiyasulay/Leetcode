class Solution {
public:
    int backtrack(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& dp)
    {
        if(row<0 || col<0) return 0;
        if(row == 0 && col == 0) return 1;
        if(dp[row][col] != -1) return dp[row][col];
        
        int left = 0;
        if(col-1>=0 && grid[row][col-1] == 0) left = backtrack(grid, row, col-1, dp);
        int up = 0;
        if(row-1>=0 && grid[row-1][col] == 0) up = backtrack(grid, row-1, col, dp);

        return dp[row][col] = left+up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1) return 0;

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return backtrack(obstacleGrid, m-1, n-1, dp);
    }
};