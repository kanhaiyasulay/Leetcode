class Solution {
public:
    void backtrack(vector<int>& nums, unordered_map<int, bool>& mp, vector<vector<int>>& ans, vector<int>& temp, int idx)
    {
        if(temp.size() == nums.size()) 
        {
            ans.push_back(temp);
            return;
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(mp[nums[i]]) continue;

            mp[nums[i]] = true;
            temp.push_back(nums[i]);
            backtrack(nums, mp, ans, temp, i+1);
            mp[nums[i]] = false;
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        unordered_map<int, bool> mp;
        for(auto it:nums ) mp[it] = false;
        vector<vector<int>> ans;
        vector<int> temp;    

        backtrack(nums, mp, ans, temp, 0);
        return ans;
    }
};