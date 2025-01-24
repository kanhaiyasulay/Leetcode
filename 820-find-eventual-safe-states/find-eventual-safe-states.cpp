class Solution {
private:
    bool dfs(vector<vector<int>>&graph, vector<int>&vis, vector<int>&pathVis, int src) {
        vis[src] = 1;
        pathVis[src] = 1;

        for(auto nbr:graph[src]) {
            if(!vis[nbr]) {
                if(dfs(graph, vis, pathVis, nbr)) return true;
            }
            else if(vis[nbr] && pathVis[nbr]) return true;
        }
        //backtracking
        pathVis[src] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                dfs(graph, vis, pathVis, i);
            }
        }

        vector<int> safeNodes;
        for(int i=0; i<n; i++) {
            if(pathVis[i] != 1) safeNodes.push_back(i);
        }

        return safeNodes;
    }
};