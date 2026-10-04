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
    int rob(vector<int>& nums) 
    {
        if(nums.size() == 1) return nums.back();
        
        int n = nums.size();
        int s = nums[0];
        nums[0] = 0;


        vector<int> dp1(n, -1);
        int exclude1st = houseRobber(nums, 0, dp1);

        nums[0] = s;
        vector<int> dp2(n-1, -1);
        nums.pop_back();
        int excludeLast = houseRobber(nums, 0, dp2);

        return max(exclude1st, excludeLast);
    }
};