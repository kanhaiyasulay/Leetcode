class Solution {
public:
    int backtrack(vector<int>& coins, int amount, int idx, vector<vector<int>>& dp)
    {
        if(idx == 0)
        {
            if(amount%coins[0] != 0) return 1e6;
            return amount/coins[0];
        }

        if(dp[idx][amount] != -1) return dp[idx][amount];

        int exclude = backtrack(coins, amount, idx-1, dp);
        int include = 1e6;
        if(coins[idx] <= amount)
            include = backtrack(coins, amount-coins[idx], idx, dp) + 1;
        
        return dp[idx][amount] = min(include, exclude);
    }
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = backtrack(coins, amount, n-1, dp);
        return ans==1e6 ? -1 : ans;
    }
};