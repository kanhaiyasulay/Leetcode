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

        int reqSum = total/2;

        vector<bool> prev(reqSum+1, false);
        vector<bool> temp(reqSum+1, false);
        prev[0] = true;

        if(nums[0] <= reqSum) prev[nums[0]] = true;

        for(int i=1; i<n; i++)
        {
            for(int sum=0; sum<=reqSum; sum++)
            {
                bool exclusion = prev[sum];
                bool inclusion = false;
                if(nums[i] <= sum)
                    inclusion = prev[sum-nums[i]];

                temp[sum] = (inclusion || exclusion);
            }
            prev = temp;
        }

        return prev.back();
    }
};
