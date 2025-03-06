class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<bool> vis((n*n)+1, false);
        vis[0] = true;

        int a = 0, b = 0;
        for(int i=1; i<vis.size(); i++)
        {
            if(vis[i]) continue;
            bool notFound = true;
            for(auto a:grid )
            {
                for(auto it:a )
                {
                    if(it == i)
                    {
                        vis[it] = true;
                        notFound = false;
                        break;
                    }
                }
                if(!notFound) break;
            }
            if(notFound)
            {
                b = i;
                break;
            }
        }

        for(int i=1; i<vis.size(); i++)
            if(i != b) vis[i] = true;

        for(auto it:grid )
        {
            for(auto a:it )
            {
                if(!vis[a] && a != b)
                {
                    vector<int> ans;
                    ans.push_back(a);
                    ans.push_back(b);
                    return ans;
                }
                vis[a] = false;
            }
        }

        return {};
    }
};