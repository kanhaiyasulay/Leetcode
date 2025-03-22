class Solution {
    void dfs(vector<int> adj[], vector<bool>&vis, vector<bool>& pathVis, int src)
    {
        vis[src] = true;
        pathVis[src] = true;

        for(auto nbr:adj[src] )
        {
            if(!vis[nbr])
            {
                dfs(adj, vis, pathVis, nbr);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) 
    {

        vector<int> adj[n];
        for(auto it:edges )
        {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt = 0;
        vector<bool> vis(n, false);
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                vector<bool> pathVis(n, false);
                dfs(adj, vis, pathVis, i);
                int tempCnt = 0;
                for(auto it:pathVis )
                {
                    if(it) tempCnt++;
                }
                
                bool check = true;
                for(int j=0; j<n; j++)
                {
                    if(pathVis[j] && adj[j].size() != tempCnt-1)
                    {
                        check = false;
                        break;
                    }
                }

                if(check) cnt++;
            }
        }

        return cnt;
    }
};