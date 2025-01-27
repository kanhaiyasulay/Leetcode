class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
    {
        int rows = mat.size(), cols = mat[0].size();
        unordered_map<int, vector<int>> mp;

        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                mp[i-j].push_back(mat[i][j]);
            }
        }

        for(auto a:mp ) 
        {
            vector<int> v = a.second;
            sort(v.begin(), v.end());
            mp[a.first] = v;
        }

        for(int i=rows-1; i>=0; i--)
        {
            for(int j=cols-1; j>=0; j--)
            {
                mat[i][j] = mp[i-j].back();
                mp[i-j].pop_back();
            }
        }

        return mat;
    }
};