class Solution {
public:
    int backtrack(vector<vector<int>>& triangle, vector<vector<int>> &dp, int row, int col)
    {
        if(row >= triangle.size() || col >= triangle[row].size())  return INT_MAX;
        if(row == triangle.size()-1) return triangle[row][col];
        if(dp[row][col] != -1) return dp[row][col];

        int down = triangle[row][col] + backtrack(triangle, dp, row+1, col);
        int digonal = triangle[row][col] + backtrack(triangle, dp, row+1, col+1);

        return dp[row][col] = min(down, digonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size(), m = triangle[n-1].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return backtrack(triangle, dp, 0, 0);
    }
};
