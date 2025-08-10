class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        int n = strs.size();
        vector<string> extra = strs;
        for(int i=0; i<n; i++)
        {
            sort(strs[i].begin(), strs[i].end());
        }
        unordered_map<string, vector<int>> mp;
        for(int i=0; i<n; i++)
        {
            mp[strs[i]].push_back(i);
        }

        vector<vector<string>> ans;
        for(auto it:mp )
        {
            vector<string> temp;
            for(auto a:it.second ) temp.push_back(extra[a]);
            ans.push_back(temp);
        }

        return ans;
    }
};