class Solution {
public:
    int backtrack(vector<vector<int>>& grid, int row, int col1, int col2, vector<vector<vector<int>>>& dp)
    {
        if(col1 >= grid[0].size() || col2 >= grid[0].size() || col1 < 0 || col2 < 0) return 0;
        if(row == grid.size()-1) 
        {
            if(col1 == col2) return grid[row][col1];
            return grid[row][col1] + grid[row][col2];
        }
        if(dp[row][col1][col2] != -1) return dp[row][col1][col2];

        int maxi = 0;
        for(int i=-1; i<2; i++)
        {
            for(int j=-1; j<2; j++)
            {
                int temp = 0;
                if(col1 == col2) 
                {
                    temp = grid[row][col1] + backtrack(grid, row+1, col1+i, col2+j, dp);
                }
                else
                {
                    temp = grid[row][col1] + grid[row][col2] + backtrack(grid, row+1, col1+i, col2+j, dp);
                }
                maxi = max(maxi, temp);
            }
        }

        return dp[row][col1][col2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int row = 0, col1 = 0, col2 = grid[0].size();
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));
        return backtrack(grid, row, col1, col2-1, dp);
    }
};