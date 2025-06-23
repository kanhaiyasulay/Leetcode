class Solution {
public:
    bool backtrack(vector<int>& nums, vector<vector<int>>& dp, int sum, int idx)
    {
        if(sum == 0) return true;
        if(idx < 0) return (sum == 0);
        if(dp[idx][sum] != -1) return dp[idx][sum];

        bool exclusion = backtrack(nums, dp, sum, idx-1);
        bool inclusion = false;
        if(nums[idx] <= sum)
            inclusion = backtrack(nums, dp, sum-nums[idx], idx-1);
        
        return dp[idx][sum] = (inclusion || exclusion);
    }
    bool canPartition(vector<int>& nums)
    {
        int total = 0, n = nums.size();

        for(auto it:nums ) total += it;
        if(total%2 != 0) return false;

        vector<vector<int>> dp(n, vector<int>((total/2)+1, -1));
        return backtrack(nums, dp, total/2, n-1);
    }
};
