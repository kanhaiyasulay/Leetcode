class Solution {
public:
    int backtrack(int n, vector<int>& dp)
    {
        for(int i=2; i<=n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp.back();
    }
    int climbStairs(int n) 
    {
        vector<int> dp(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;
        return backtrack(n, dp);    
    }
};