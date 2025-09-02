class Solution {
    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, 1, 0, -1};
public:
    void bfs(vector<vector<int>>& image, int row, int col, int color, int orgColor, vector<vector<bool>>& vis)
    {
        int n = image.size(), m = image[0].size();
        
        queue<pair<int,int>> q;
        q.push({row, col});

        while(!q.empty())
        {
            row = q.front().first;
            col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && image[nrow][ncol] == orgColor)
                {
                    vis[nrow][ncol] = true;
                    q.push({nrow, ncol});
                    image[nrow][ncol] = color;
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int n = image.size(), m = image[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int orgColor = image[sr][sc];
        image[sr][sc] = color;
        vis[sr][sc] = true;
        bfs(image, sr, sc, color, orgColor, vis);
        return image;
    }
};