class Solution {
    bool isSafe(vector<string>& board, int row, int col, int n)
    {
        // Check upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // Check lower-left diagonal
        for (int i = row, j = col; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }
public:
    void nQueen(int n, vector<vector<string>>& ans, vector<string>& temp, int row, int col, vector<bool>& rowCheck)
    {
        if(col >= n)
        {
            ans.push_back(temp);
            return;
        }

        for(int r=0; r<n; r++)
        {
            if(rowCheck[r]) continue;

            if(!isSafe(temp, r, col, n)) continue;

            temp[r][col] = 'Q';
            rowCheck[r] = true;

            nQueen(n, ans, temp, r, col+1, rowCheck);

            temp[r][col] = '.';
            rowCheck[r] = false;
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;
        vector<string> temp(n, string(n, '.'));
        vector<bool> rowCheck(n, false);

        nQueen(n, ans, temp, 0, 0, rowCheck);
        return ans;
    }
};