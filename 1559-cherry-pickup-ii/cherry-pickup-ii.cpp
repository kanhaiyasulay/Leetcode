class Solution {
public:
    int backtrack(vector<vector<int>>& grid, int row, int col1, int col2, vector<vector<vector<int>>>& dp)
    {
        int m = grid[0].size(), n = grid.size();
        if(col1 < 0 || col1 >= m || col2 < 0 || col2 >= m) return -10000;
        if(row == n) return 0;
        if(dp[row][col1][col2] != -1) return dp[row][col1][col2];

        int maxi = 0;
        for(int i=-1; i<2; i++)
        {
            for(int j=-1; j<2; j++)
            {
                int totCherries = grid[row][col1] + grid[row][col2];
                if(col1 == col2) totCherries = grid[row][col1];
                int curr = totCherries + backtrack(grid, row+1, col1+i, col2+j, dp);
                maxi = max(maxi, curr);
            }
        }

        return dp[row][col1][col2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int col = grid[0].size(), row = grid.size();
        vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(col, -1)));
        return backtrack(grid, 0, 0, col-1, dp);
    }
};