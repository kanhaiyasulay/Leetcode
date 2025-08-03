class Solution {
public:
    int backtrack(vector<vector<int>>& obstacleGrid, int row, int col, vector<vector<int>>& dp) 
    {
        if (row < 0 || col < 0 || obstacleGrid[row][col] == 1) return 0;
        if (row == 0 && col == 0) return 1;

        if(dp[row][col] != -1) return dp[row][col];

        int left = backtrack(obstacleGrid, row, col - 1, dp);
        int up = backtrack(obstacleGrid, row - 1, col, dp);

        return dp[row][col] = left + up;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1) return 0;

        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = 1;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(obstacleGrid[i][j] == 1 || (i == 0 && j == 0)) continue;
                int up = 0, left = 0;
                if(i > 0)
                    up = dp[i-1][j];
                if(j > 0)
                    left = dp[i][j-1];
                
                dp[i][j] = up + left;
            }
        }

        return dp[n-1][m-1];
    }
};
