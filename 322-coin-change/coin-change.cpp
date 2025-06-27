class Solution {
public:
    int backtrack(vector<int>& coins, vector<vector<int>>& dp, int amount, int idx)
    {
        if(amount == 0) return 0;
        if(idx < 0) return 1e9;
        if(dp[idx][amount] != -1) return dp[idx][amount];
        
        int exclusion = 0 + backtrack(coins, dp, amount, idx-1);
        int inclusion = 1e9;
        if(coins[idx] <= amount)
            inclusion = 1 + backtrack(coins, dp, amount-coins[idx], idx);

        return dp[idx][amount] = min(inclusion, exclusion);
    }
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = backtrack(coins, dp, amount, n-1);
        return ans == 1e9 ? -1 : ans;
    }
};
