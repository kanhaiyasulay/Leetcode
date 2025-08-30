class Solution {
public:
    void allSubs(vector<int>& nums, int k, int target, vector<vector<int>>& ans, vector<int>& temp, int idx)
    {
        if(temp.size() == k) 
        {
            if(target == 0) ans.push_back(temp);
            return;
        }

        for(int i=idx; i<nums.size(); i++)
        {
            if(nums[i] > target) break;
            temp.push_back(nums[i]);
            allSubs(nums, k, target-nums[i], ans, temp, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> temp;
        allSubs(nums, k, n, ans, temp, 0);
        return ans;
    }
};