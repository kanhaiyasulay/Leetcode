class Solution {
public:
    int backtrack(vector<vector<int>>& matrix, int col, int row, vector<vector<int>>& dp)
    {
        if(col >= matrix.size() || col < 0) return 1e9;
        if(row == 0) return matrix[row][col];

        if(dp[row][col] != INT_MAX) return dp[row][col];

        int mini = INT_MAX;
        for(int i=-1; i<=1; i++)
        {
            int curr = matrix[row][col] + backtrack(matrix, col+i, row-1, dp);
            mini = min(mini, curr);
        }
        
        return dp[row][col] = mini;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        int mini = INT_MAX;
        for(int i=0; i<n; i++)
        {
            mini = min(mini, backtrack(matrix, i, n-1, dp));
        }

        return mini;
    }
};