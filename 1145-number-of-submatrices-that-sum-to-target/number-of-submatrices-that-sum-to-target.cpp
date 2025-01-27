class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) 
    {
        int rows = matrix.size(), cols = matrix[0].size(), cnt = 0;
        vector<vector<int>> arr(rows, vector<int>(cols));


        for(int i=0; i<rows; i++)
        {
            int sum = 0;
            for(int j=0; j<cols; j++)
            {
                sum += matrix[i][j];
                arr[i][j] = sum;
            }
        }

        for(int startCol = 0; startCol < cols; startCol++)
        {
            for(int endCol = startCol; endCol < cols; endCol++)
            {
                unordered_map<int, int> mp;
                mp.insert({0, 1});

                int cumSum = 0;

                for(int row=0; row<rows; row++)
                {
                    cumSum += arr[row][endCol] - (startCol > 0 ? arr[row][startCol-1] : 0);

                    int remove = cumSum - target;
                    if(mp.find(remove) != mp.end())
                        cnt += mp[remove];
                    mp[cumSum]++;
                }
            }
        }

        return cnt;
    }
};