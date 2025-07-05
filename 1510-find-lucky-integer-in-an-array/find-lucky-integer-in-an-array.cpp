class Solution {
public:
    int findLucky(vector<int>& arr) 
    {
        unordered_map<int, int> mp;
        for(auto it:arr ) mp[it]++;
        int luckyInt = -1;
        for(auto it:mp )
        {
            if(it.first == it.second) 
                luckyInt = max(luckyInt, it.first);
        }

        return luckyInt;
    }
};