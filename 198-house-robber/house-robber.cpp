class Solution {
public:
    int backtrack(vector<int>& nums, int idx, vector<int>& dp)
    {
        if(idx < 0) return 0;
        if(idx == 0) return nums[0];

        if(dp[idx] != -1) return dp[idx];

        int inclusion = nums[idx] + backtrack(nums, idx-2, dp);
        int exclusion = backtrack(nums, idx-1, dp);

        return dp[idx] = max(inclusion, exclusion);
    }
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return backtrack(nums, n-1, dp);
    }
};