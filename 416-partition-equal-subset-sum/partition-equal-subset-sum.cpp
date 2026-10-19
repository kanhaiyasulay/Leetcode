class Solution {
public:
    bool backtrack(vector<int>& nums, int sum, int idx, vector<vector<int>>& dp)
    {
        if(idx == 0) return nums[0] == sum;
        if(idx < 0) return false;
        if(dp[idx][sum] != -1) return dp[idx][sum];

        int exclusion = backtrack(nums, sum, idx-1, dp);
        int inclusion = false;
        if(sum >= nums[idx])
            inclusion = backtrack(nums, sum-nums[idx], idx-1, dp);
        
        return dp[idx][sum] = inclusion || exclusion;
    }
    bool canPartition(vector<int>& nums) 
    {
        int sum = 0;
        for(auto it:nums )    sum += it;
        if(sum&1) return false;

        int target = sum/2;
        vector<vector<int>> dp(nums.size(), vector<int>(target+1, -1));
        return backtrack(nums, target, nums.size()-1, dp);
    }
};