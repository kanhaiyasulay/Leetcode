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
        vector<vector<int>> dp(n, vector<int>(n, 1e9));

        for(int i=0; i<n; i++)
        {
            dp[0][i] = matrix[0][i];
        }

        for(int i=1; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int minus1 = INT_MAX, zero = INT_MAX, plus1 = INT_MAX;

                zero = matrix[i][j] + dp[i-1][j];
                if(j-1 >= 0)
                    minus1 = matrix[i][j] + dp[i-1][j-1];
                if(j+1 <= n-1)
                    plus1 = matrix[i][j] + dp[i-1][j+1];

                dp[i][j] = min({minus1, zero, plus1});
            }
        }

        int mini = INT_MAX;
        for(int i=0; i<n; i++) mini = min(mini, dp[n-1][i]);
        return mini;
    }
};