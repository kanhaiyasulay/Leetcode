class Solution {
public:
    bool checkRow(vector<vector<int>>& mat, int row)
    {
        for(int i=0; i<mat[row].size(); i++)
        {
            if(mat[row][i] != -1) return false;
        }
        return true;
    }
    bool checkCol(vector<vector<int>>& mat, int col)
    {
        for(int i=0; i<mat.size(); i++)
        {
            if(mat[i][col] != -1) return false;
        }
        return true;
    }
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) 
    {
        unordered_map<int, int> mp;
        unordered_map<int, int> np;

        for(int i=0; i<mat.size(); i++)
        {
            for(int j=0; j<mat[i].size(); j++)
            {
                mp[mat[i][j]] = i;
                np[mat[i][j]] = j;
            }
        }

        vector<int> trackRow(mat.size(), mat[0].size());
        vector<int> trackCol(mat[0].size(), mat.size());

        for(int i=0; i<arr.size(); i++)
        {
            int row = mp[arr[i]];
            int col = np[arr[i]];

            trackRow[row]--;
            trackCol[col]--;
            if(trackRow[row] == 0) return i;
            if(trackCol[col] == 0) return i;
        }
        return -1;
    }
};