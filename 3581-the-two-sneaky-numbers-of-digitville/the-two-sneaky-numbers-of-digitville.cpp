class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) 
    {
        unordered_map<int,int> mp;
        vector<int> v;
        for(auto it:nums ) 
        {
            if(mp.find(it) != mp.end()) v.push_back(it);
            mp[it]++;
        }

        return v;
    }
};