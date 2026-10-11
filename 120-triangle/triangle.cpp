class Solution {
public:
    int backtrack(vector<vector<int>>& triangle, int row, int col, vector<vector<int>>& dp)
    {
        if(row<0 || col>=triangle[row].size() || col<0) return 1e9;
        if(row==0 && col==0) return triangle[0][0];
        if(dp[row][col] != -1) return dp[row][col];

        int up = 1e9, upLeft = 1e9;
        if(row-1>=0 && triangle[row-1].size() > col) up = backtrack(triangle, row-1, col, dp) + triangle[row][col];
        if(row-1>=0 && col-1>=0) upLeft = backtrack(triangle, row-1, col-1, dp) + triangle[row][col];

        return dp[row][col] = min(up, upLeft);
    }
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int m = triangle.size();
        int n = triangle[m-1].size();
        int minAns = INT_MAX;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i=0; i<triangle[m-1].size(); i++)
        {
            int ans = backtrack(triangle, m-1, i, dp);
            minAns = min(minAns, ans);
        }
        return minAns;
    }
};