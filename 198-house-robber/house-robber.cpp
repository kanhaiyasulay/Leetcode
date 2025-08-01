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
        if(n == 1) return nums[0];

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i=2; i<n; i++)
        {
            int inclusion = 0;
            if(i-2 >= 0)
                inclusion = nums[i] + dp[i-2];
            int exclusion = dp[i-1];

            dp[i] = max(inclusion, exclusion);
        }

        return dp.back();
    }
};