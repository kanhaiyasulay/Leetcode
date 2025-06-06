class Solution {
public:
    int memoization(int n, vector<int>& dp)
    {
        if(n <= 2) return n;

        if(dp[n] != -1) return dp[n];
        return dp[n] = memoization(n-1, dp) + memoization(n-2, dp);
    }
    int climbStairs(int n) 
    {
        vector<int> dp(n+1, -1);
        return memoization(n, dp);
    }
};