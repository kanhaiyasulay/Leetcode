class Solution {
public:
    int backtrack(vector<int>& nums, int target, int idx, vector<vector<int>>& dp)
    {
        if(idx == 0)
        {
            if(target == 0 && target == nums[0]) return 2;
            if(target == 0) return 1;
            if(target == nums[0]) return 1;
            return 0;
        }
        if(dp[idx][target] != -1) return dp[idx][target];
        
        int exclusion = backtrack(nums, target, idx-1, dp);
        int inclusion = 0;
        if(target >= nums[idx])
            inclusion = backtrack(nums, target-nums[idx], idx-1, dp);
        
        return dp[idx][target] = (inclusion + exclusion);
    }
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int newTarget = (total+target)/2;
        // VV IMP
        if (total < abs(target) || (target + total) % 2 != 0) return 0;

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(newTarget+1, 0));

        for(int i=0; i<n; i++) dp[i][0] = 1;
        if(newTarget >= nums[0]) dp[0][nums[0]] += 1;

        for(int i=1; i<n; i++)
        {
            for(int tar=0; tar<=newTarget; tar++)
            {
                int exclusion = dp[i-1][tar];
                int inclusion = 0;
                if(tar >= nums[i])
                    inclusion = dp[i-1][tar-nums[i]];
                
                dp[i][tar] = inclusion + exclusion;
            }
        }

        return dp[n-1][newTarget];
    }
};