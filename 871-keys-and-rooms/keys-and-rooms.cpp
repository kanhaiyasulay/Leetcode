class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<bool>& vis, int src)
    {
        vis[src] = true;
        for(auto it:rooms[src] )
        {
            if(!vis[it])
            {
                dfs(rooms, vis, it);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int n = rooms.size();
        vector<bool> vis(n, false);
        dfs(rooms, vis, 0);

        for(auto a:vis ) if(!a) return false;
        return true;
    }
};