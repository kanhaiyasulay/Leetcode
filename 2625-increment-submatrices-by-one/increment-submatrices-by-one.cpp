class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) 
    {
        vector<vector<int>> arr(n, vector<int>(n, 0));

        for(int i=0; i<queries.size(); i++)
        {
            int sRow = queries[i][0];
            int sCol = queries[i][1];
            int eRow = queries[i][2];
            int eCol = queries[i][3];

            for(int j=sRow; j<=eRow; j++)
            {
                for(int k=sCol; k<=eCol; k++) arr[j][k]++;
            }
        }

        return arr;
    }
};