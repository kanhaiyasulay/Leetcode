class Solution {
public:
    int backtrack(vector<int>& coins, int amount, int idx, vector<vector<int>>& dp)
    {
        if(idx == 0)
        {
            if(amount%coins[0] == 0) return 1;
            return 0;
        }
        if(dp[idx][amount] != -1) return dp[idx][amount];

        int exclusion = backtrack(coins, amount, idx-1, dp);
        int inclusion = 0;
        if(coins[idx] <= amount)
            inclusion = backtrack(coins, amount-coins[idx], idx, dp);
        
        return dp[idx][amount] = (inclusion + exclusion);
    }
    int change(int amount, vector<int>& coins) 
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return backtrack(coins, amount, n-1, dp);
    }
};