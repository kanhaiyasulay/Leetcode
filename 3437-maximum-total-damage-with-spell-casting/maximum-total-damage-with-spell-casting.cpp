class Solution {
public:
    typedef long long ll;        

    long long solve(int i, const vector<ll>& nums, unordered_map<ll, ll>& mp, vector<ll>& dp) {
        if (i >= nums.size()) 
            return 0;

        if (dp[i] != -1) return dp[i];

        //skip current damage
        ll skip = solve(i + 1, nums, mp, dp);

        //take current damage using binary search
        int j = lower_bound(begin(nums) + i + 1, end(nums), nums[i] + 3) - begin(nums);
        ll take = nums[i] * mp[nums[i]] + solve(j, nums, mp, dp);

        return dp[i] = max(skip, take);
    }

    long long maximumTotalDamage(vector<int>& power) 
    {
        int n = power.size();
        unordered_map<ll,ll> mp;      
        for (int x : power) 
            mp[x]++;

        vector<ll> nums;

        for (auto &p : mp)
            nums.push_back(p.first);
                      
        vector<ll> dp(n, -1);
        sort(begin(nums), end(nums));

        return solve(0, nums, mp, dp);
    }
};