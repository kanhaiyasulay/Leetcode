class Solution {
public:
    int houseRobber(vector<int>& nums, int idx, vector<int>& dp)
    {
        int n = nums.size();
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];

        int inclusion = houseRobber(nums, idx+2, dp) + nums[idx];
        int exclusion = houseRobber(nums, idx+1, dp);

        return dp[idx] = max(inclusion, exclusion);
    }
    int tabulization(vector<int>& nums, int n)
    {
        vector<int> dp(n, -1);
        dp[0] = nums[0];

        for(int i=1; i<n; i++)
        {
            int inclusion = nums[i];
            if(i-2 >= 0)
                inclusion += dp[i-2];
            int exclusion = dp[i-1];

            dp[i] = max(inclusion, exclusion);
        }

        return dp.back();
    }
    int rob(vector<int>& nums) 
    {
        if(nums.size() == 1) return nums.back();

        int n = nums.size();
        int s = nums[0];
        nums[0] = 0;
        int exclude1st = tabulization(nums, n);

        nums[0] = s;
        nums.pop_back();
        int excludeLast = tabulization(nums, nums.size());

        return max(exclude1st, excludeLast);
    }
};