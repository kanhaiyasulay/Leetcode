class Solution {
public:
    bool isSafe(vector<string>& tempAns, int row, int col)
    {
        int n = tempAns.size();
        for(int i=0; i<col; i++)
        {
            if(tempAns[row][i] == 'Q') return false;
        }
        // int tempCol = col;
        // while(tempCol >= 0)
        // {
        //     if(tempAns[row][tempCol] == 'Q') return false;
        //     tempCol--;
        // }

        int tRow = row, tCol = col;
        while(tRow >= 0 && tCol >= 0)
        {
            if(tempAns[tRow][tCol] == 'Q') return false;
            tRow--;
            tCol--;
        }

        tRow = row;
        tCol = col;
        while(tRow < n && tCol >= 0)
        {
            if(tempAns[tRow][tCol] == 'Q') return false;
            tRow++;
            tCol--;
        }

        return true;
    }
    void backtrack(vector<vector<string>>& ans, vector<string>& tempAns, int col)
    {
        int n = tempAns.size();
        if(col >= n) 
        {
            ans.push_back(tempAns);
            return;
        }

        for(int i=0; i<n; i++)
        {
            if(isSafe(tempAns, i, col))
            {
                tempAns[i][col] = 'Q';
                backtrack(ans, tempAns, col+1);
                tempAns[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;
        vector<string> tempAns;
        string temp(n, '.');
        for(int i=0; i<n; i++) tempAns.push_back(temp);

        backtrack(ans, tempAns, 0);

        return ans;
    }
};