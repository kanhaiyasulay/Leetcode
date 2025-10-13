typedef long long ll;
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        sort(potions.begin(), potions.end());

        vector<int> ans;

        int n = spells.size();
        for(int i=0; i<n; i++)
        {
            ll target = success / spells[i];
            target += (success%spells[i]) != 0 ? 1 : 0;

            auto it = std::lower_bound(potions.begin(), potions.end(), target);

            if(it != potions.end()) ans.push_back(potions.end()-it);
            else ans.push_back(0);
        }

        return ans;
    }
};