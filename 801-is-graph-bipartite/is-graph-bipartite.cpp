 class Solution {
public:
    bool bfs(vector<vector<int>>& graph, vector<int>& color, int src)
    {
        queue<pair<int, int>> q;
        q.push({src, 1});
        color[src] = 1;

        while(!q.empty())
        {
            int node = q.front().first;
            int clr = q.front().second;
            q.pop();

            for(auto it:graph[node] )
            {
                if(color[it] == -1)
                {
                    color[it] = !clr;
                    q.push({it, !clr});
                }
                if(color[it] == clr) return false;
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i=0; i<n; i++)    
        {
            if(color[i] == -1)
            {
                if(bfs(graph, color, i) == false) return false;
            }
        }
        return true;
    }
};