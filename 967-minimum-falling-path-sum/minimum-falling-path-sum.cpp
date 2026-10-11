class Solution {
public:
    int backtrack(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& dp)
    {
        if(row<0 || col<0 || col>=matrix[0].size()) return 1e9;
        if(row==0) return matrix[row][col];
        if(dp[row][col] != 1e9) return dp[row][col];

        int mini = 1e9;
        for(int i=-1; i<2; i++)
        {
            int ans = backtrack(matrix, row-1, col+i, dp) + matrix[row][col];
            mini = min(mini, ans);
        }
        return dp[row][col] = mini;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int minAns = INT_MAX;
        vector<vector<int>> dp(m, vector<int>(m, 1e9));
        for(int i=0; i<m; i++)
        {
            int ans = backtrack(matrix, m-1, i, dp);
            minAns = min(minAns, ans);
        }
        return minAns;
    }
};