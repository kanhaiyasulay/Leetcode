class Solution {
public:
    bool dfs(vector<int> adj[], vector<int>& color, int src, int currColor)
    {
        color[src] = currColor;
        for(auto it:adj[src])
        {
            if(color[it] == -1)
            {
                color[it] = !color[src];
                if(!dfs(adj, color, it, color[it])) return false;
            }
            else if(color[it] == color[src]) return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) 
    {
        vector<int> adj[n+1];
        for(auto it:dislikes )
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> color(n+1, -1);
        
        for(int i=1; i<=n; i++)
        {
            if(color[i] == -1)
            {
                if(!dfs(adj, color, i, 0)) return false;
            }
        }

        return true;
    }
};