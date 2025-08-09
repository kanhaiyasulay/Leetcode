class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int src)
    {
        for(auto it:graph[src] )
        {
            if(color[it] == -1)
            {
                color[it] = !color[src];
                if(!dfs(graph, color, it)) return false;
            }
            if(color[it] == color[src]) return false;
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
                color[i] = 1;
                if(dfs(graph, color, i) == false) return false;
            }
        }
        return true;
    }
};