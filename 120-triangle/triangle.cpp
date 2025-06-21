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
        int n = triangle.size();
        vector<int> prev(n, 0);

        for(int i=0; i<n; i++)
            prev[i] = triangle[n-1][i];
        
        for(int i=n-2; i>=0; i--)
        {
            vector<int> temp(n, 0);
            for(int j=i; j>=0; j--)
            {
                int down = triangle[i][j] + prev[j];
                int digonal = triangle[i][j] + prev[j+1];

                temp[j] = min(down, digonal);
            }
            prev = temp;
        }

        return prev[0];
    }
};
