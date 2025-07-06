#define ll long long
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
        vector<vector<unsigned ll>> dp(n, vector<unsigned ll>(amount+1, 0));

        for(int i=0; i<=amount; i++)
        {
            if(i%coins[0] == 0) dp[0][i] = 1;
            else dp[0][i] = 0;
        }

        for(int i=1; i<n; i++)
        {
            for(int amt=0; amt<=amount; amt++)
            {
                unsigned ll exclusion = dp[i-1][amt];
                unsigned ll inclusion = 0;
                if(amt >= coins[i])
                    inclusion = dp[i][amt-coins[i]];
                
                dp[i][amt] = inclusion + exclusion;
            }
        }

        return static_cast<int>(dp[n-1][amount]);
    }
};