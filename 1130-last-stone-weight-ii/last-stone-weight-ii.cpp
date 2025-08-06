class Solution {
public:
    int backtrack(vector<int>& stones, int target, int idx, int currentSum, vector<vector<int>>& dp) 
    {
        if(currentSum > target) return 0;
        if (idx < 0) 
        {
            if (currentSum <= target) return currentSum;
            return 0;
        }
        if(dp[idx][currentSum] != -1) return dp[idx][currentSum];

        int inclusion = backtrack(stones, target, idx - 1, currentSum + stones[idx], dp);
        int exclusion = backtrack(stones, target, idx - 1, currentSum, dp);

        return dp[idx][currentSum] = max(inclusion, exclusion);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int tot = accumulate(stones.begin(), stones.end(), 0);
        int target = tot / 2;
        int n = stones.size();

        vector<vector<int>> dp(n, vector<int>(target+1, -1));

        int ans = backtrack(stones, target, stones.size() - 1, 0, dp);
        return tot - 2 * ans;
    }
};
