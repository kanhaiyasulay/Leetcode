class Solution {
public:
    bool isSafe(char ch, vector<vector<char>>& board, int row, int col)
    {
        // 1. checking for 3X3 metrix
        int startRow = row-(row%3);
        int startCol = col - (col%3);
        for(int i=startRow; i<startRow+3; i++)
        {
            for(int j=startCol; j<startCol+3; j++)
            {
                if(board[i][j] == ch) return false;
            }
        }

        // 2. checking for entire row 
        for(int i=0; i<9; i++)
        {
            if(board[row][i] == ch) return false;
        }

        // 3. checking for entire col
        for(int i=0; i<9; i++)  
        {
            if(board[i][col] == ch) return false;
        }

        return true;
    }
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
                        if(!isSafe(ch, board, i, j)) continue;
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