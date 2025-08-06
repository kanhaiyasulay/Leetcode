class Solution {
public:
    int mini = 0; // closest sum to target

    void backtrack(vector<int>& stones, int target, int idx, int currentSum, vector<vector<int>>& dp) 
    {
        if(currentSum > target) return;
        if (idx < 0) 
        {
            if (currentSum <= target)
                mini = max(mini, currentSum); // track the best sum ≤ target
            return;
        }
        if(dp[idx][currentSum] != -1)
        {
            mini = max(mini, dp[idx][currentSum]);
            return;
        }
        if(currentSum <= target) dp[idx][currentSum] = mini;

        // include current stone
        backtrack(stones, target, idx - 1, currentSum + stones[idx], dp);
        // exclude current stone
        backtrack(stones, target, idx - 1, currentSum, dp);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int tot = accumulate(stones.begin(), stones.end(), 0);
        int target = tot / 2;
        int n = stones.size();

        vector<vector<int>> dp(n, vector<int>(target+1, -1));

        backtrack(stones, target, stones.size() - 1, 0, dp);
        return tot - 2 * mini;
    }
};
