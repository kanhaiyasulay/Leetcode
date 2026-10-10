class Solution {
public:
    int backtrack(int m, int n, int row, int col, vector<vector<int>>& dp)
    {
        if(row<0 || col<0 || row>=m || col>=n) return 0;
        if(row==0 && col==0) return 1;
        if(dp[row][col] != -1) return dp[row][col];

        int left = backtrack(m, n, row, col-1, dp);
        int down = backtrack(m, n, row-1, col, dp);

        return dp[row][col] = left+down;
    }
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int row=0; row<m; row++)
        {
            for(int col=0; col<n; col++)
            {
                if(row == 0 && col == 0) dp[0][0] = 1;
                else
                {
                    int up = 0, left = 0;
                    if(row-1 >= 0) up = dp[row-1][col];
                    if(col-1 >= 0) left = dp[row][col-1];

                    dp[row][col] = up + left;
                }
            }
        }

        return dp[m-1][n-1];
    }
};