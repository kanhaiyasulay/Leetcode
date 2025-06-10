class Solution {
    bool isSafe(vector<vector<char>>& board, char ch, int row, int col)
    {
        for(int j=0; j<board.size(); j++)
        {
            if(board[row][j] == ch || board[j][col] == ch) 
                return false;
        }

        int currRow = row - (row%3), currCol = col - (col%3);

        for(int i=currRow; i<currRow+3; i++)
            for(int j=currCol; j<currCol+3; j++)
                if(board[i][j] == ch) return false;

        return true;
    }
public:
    bool backtrack(vector<vector<char>>& board)
    {
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j] == '.')
                {
                    for(char ch='1'; ch<='9'; ch++)
                    {
                        if(!isSafe(board, ch, i, j)) continue;
                        board[i][j] = ch;
                        if(backtrack(board)) return true;
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) 
    {
        backtrack(board);
    }
};