class Solution {
public:
    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, 1, 0, -1};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
    {
        int n = maze.size();
        int m = maze[0].size();

        queue<pair<int, pair<int,int>>> q;
        q.push({0, {entrance[0], entrance[1]}});

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vis[entrance[0]][entrance[1]] = true;

        while(!q.empty())
        {
            int step = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            if(step != 0 && (row == n-1 || col == m-1 || row == 0 || col == 0)) return step;

            for(int i=0; i<4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && maze[nrow][ncol] == '.')
                {
                    q.push({step+1, {nrow, ncol}});
                    vis[nrow][ncol] = true;
                }
            }
        }

        return -1;
    }
};