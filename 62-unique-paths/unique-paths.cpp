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
        vector<int> dp(n, -1);

        for(int row=0; row<m; row++)
        {
            vector<int> tempDp(n, -1);
            for(int col=0; col<n; col++)
            {
                if(row == 0 && col == 0) tempDp[0] = 1;
                else
                {
                    int up = 0, left = 0;
                    if(row-1 >= 0) up = dp[col];
                    if(col-1 >= 0) left = tempDp[col-1];

                    tempDp[col] = up + left;
                }
            }
            dp = tempDp;
        }

        return dp.back();
    }
};