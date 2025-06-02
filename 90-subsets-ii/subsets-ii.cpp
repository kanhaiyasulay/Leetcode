class Solution {
public:
    void subs(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, int idx)
    {
        ans.push_back(temp);

        for(int i=idx; i<nums.size(); i++)
        {
            if(i>idx && nums[i] == nums[i-1]) continue;
            
            temp.push_back(nums[i]);
            subs(nums, ans, temp, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        subs(nums, ans, temp, 0);
        return ans;
    }
};