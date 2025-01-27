class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
    {
        int rows = mat.size(), cols = mat[0].size();

        for(int i=0; i<rows; i++)
        {
            int currR = i;
            int currC = 0;
            vector<int> v;
            while(currR < rows && currC < cols)
            {
                v.push_back(mat[currR][currC]);
                currR++; currC++;
            }

            sort(v.begin(), v.end());
            currR = i; currC = 0;
            int idx = 0;

            while(currR < rows && currC < cols)
            {
                mat[currR][currC] = v[idx];
                currR++; currC++; idx++;
            }
        }

        for(int i=1; i<cols; i++)
        {
            int currC = i;
            int currR = 0;
            vector<int> v;
            while(currR < rows && currC < cols)
            {
                v.push_back(mat[currR][currC]);
                currR++; currC++;
            }

            sort(v.begin(), v.end());
            currC = i; currR = 0;
            int idx = 0;

            while(currR < rows && currC < cols)
            {
                mat[currR][currC] = v[idx];
                currR++; currC++; idx++;
            }
        }

        return mat;
    }
};