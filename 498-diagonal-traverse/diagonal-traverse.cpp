class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) 
    {
        int rows = mat.size(), cols = mat[0].size();
        unordered_map<int, vector<int>> mp;

        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                mp[i+j].push_back(mat[i][j]);
            }
        }

        vector<int> ans;
        for(int i=0; i<mp.size(); i++)
        {
            vector<int> v = mp[i];
            if(i%2 == 0)
                reverse(v.begin(), v.end());
            ans.insert(ans.end(), v.begin(), v.end());
        }

        return ans;
    }
};