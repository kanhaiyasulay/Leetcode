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
        vector<int> prev(m, 0), temp(m, 0);

        prev[0] = grid[0][0];
        temp[0] = grid[0][0];
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i==0 && j==0) continue;

                int up = 1e9, left = 1e9;
                if(i>0) up = grid[i][j] + prev[j];
                if(j>0) left = grid[i][j] + temp[j-1];

                temp[j] = min(up, left);
            }
            prev = temp;
        }

        return prev.back();
    }
};
