class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) 
    {
        int n = basket1.size();
        unordered_map<int, int> mp;

        for(auto it:basket1 ) mp[it]++;
        for(auto it:basket2 ) mp[it]--;

        vector<int> ans;
        int mini = INT_MAX;
        for(auto it:mp )
        {
            mini = min(mini, it.first);
            if(it.second == 0) continue;
            else 
            {
                if(abs(it.second)%2 != 0) return -1;

                for(int i=0; i<abs(it.second)/2; i++) 
                    ans.push_back(it.first);
            }
        }

        long long cnt = 0;
        sort(ans.begin(), ans.end());

        for(int i=0; i<ans.size()/2; i++)
        {
            cnt += min(ans[i], mini*2);
        }

        return cnt;
    }
};