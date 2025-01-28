class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> ans(rows, vector<int>(cols));

        for(int i=0; i<cols; i++)
        {
            for(int j=rows-1; j>=0; j--)
            {
                ans[i][rows-1-j] = matrix[j][i];
            }
        }

        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                matrix[i][j] = ans[i][j];
            }
        }
    }
};