class Solution {
    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, 1, 0, -1};
public:
    void bfs(vector<vector<int>>& isWater, vector<vector<bool>>& vis, vector<vector<int>>& height, queue<pair<pair<int,int>, int>>& q)
    {
        int n = isWater.size(), m = isWater[0].size();
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            for(int i=0; i<4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol])
                {
                    vis[nrow][ncol] = true;
                    q.push({{nrow, ncol}, dist+1});
                    height[nrow][ncol] = dist+1;
                }
            }
        }
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) 
    {
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<int>> height(n, vector<int>(m, -1));

        queue<pair<pair<int,int>, int>> q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(isWater[i][j])
                {
                    vis[i][j] = true;
                    height[i][j] = 0;
                    q.push({{i, j}, 0});
                }
            }
        }

        bfs(isWater, vis, height, q);
        return height;
    }
};