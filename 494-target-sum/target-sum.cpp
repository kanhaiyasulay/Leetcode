class Solution {
public:
    int diffEqlToK(vector<int>& nums, int total, int target, int sum, int idx, vector<vector<int>>& dp)
    {
        if(idx < 0)
        {
            if (2 * sum == total + target) return 1;
            return 0;
        }
        if(dp[idx][sum] != -1) return dp[idx][sum];

        int inclusion = diffEqlToK(nums, total, target, sum+nums[idx], idx-1, dp);
        int exclusion = diffEqlToK(nums, total, target, sum, idx-1, dp);

        return dp[idx][sum] = inclusion + exclusion;
    }
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(total+1, -1));
        return diffEqlToK(nums, total, target, 0, n-1, dp);
    }
};
