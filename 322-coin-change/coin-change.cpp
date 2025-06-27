class Solution {
public:
    int backtrack(vector<int>& coins, vector<vector<int>>& dp, int amount, int idx)
    {
        if(idx == 0)
        {
            if(amount%coins[idx] == 0) return amount/coins[idx];
            return 1e9;
        }
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
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));

        for(int i=0; i<=amount; i++)
        {
            if(i%coins[0] == 0) dp[0][i] = i/coins[0];
            else dp[0][i] = 1e9;
        }
        for(int i=1; i<n; i++)
        {
            for(int amt = 0; amt <= amount; amt++)
            {
                int exclusion = 0 + dp[i-1][amt];
                int inclusion = 1e9;
                if(coins[i] <= amt)
                    inclusion = 1 + dp[i][amt-coins[i]];

                dp[i][amt] = min(inclusion, exclusion);
            }
        }

        return dp[n-1][amount] == 1e9 ? -1 : dp[n-1][amount];
    }
};
