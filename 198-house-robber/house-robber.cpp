class Solution {
public:
    int backtrack(vector<int>& nums, int idx, vector<int>& dp)
    {
        if(idx >= nums.size()) return 0;
        if(dp[idx] != -1) return dp[idx];

        int inclusion = backtrack(nums, idx+2, dp) + nums[idx];
        int exclusion = backtrack(nums, idx+1, dp);

        return dp[idx] = max(inclusion, exclusion);
    }
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = nums[0];

        for(int i=1; i<n; i++)
        {
            int inclusion = nums[i];
            if(i-2 >= 0) inclusion += dp[i-2];
            int exclusion = dp[i-1];

            dp[i] = max(inclusion, exclusion);
        }

        return dp.back();
    }
};