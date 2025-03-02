class Solution {
    bool dfs(vector<int> edges[], int src, int dest, vector<bool>& vis)
    {
        vis[src] = true;
        if(src == dest) return true;
        for(auto it:edges[src])
        {
            if(!vis[it])
            {
                if(dfs(edges, it, dest, vis)) return true;
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        vector<int> adj[n];
        for(auto& it:edges )
        {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n, false);
        return dfs(adj, source, destination, vis);
    }
};