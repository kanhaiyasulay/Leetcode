class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) 
    {
        unordered_map<int, int> mp;
        unordered_map<int, int> track;
        vector<int> ans;
        for(int i=0; i<queries.size(); i++)
        {
            int ball = queries[i][0];
            int color = queries[i][1];

            if(track.find(ball) != track.end())
            {
                mp[track[ball]]--;
                if(mp[track[ball]] == 0) mp.erase(track[ball]);
            }
            track[ball] = color;
            mp[color]++;
            ans.push_back(mp.size());
        }

        return ans;
    }
};