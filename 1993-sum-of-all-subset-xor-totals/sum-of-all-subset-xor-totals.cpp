class Solution {
    void inclusionExclusion(vector<int>& nums, int& ans, int xorSum, int idx)
    {
        if(idx >= nums.size())
        {
            ans += xorSum;
            return;
        }

        xorSum ^= nums[idx];
        inclusionExclusion(nums, ans, xorSum, idx+1);
        xorSum ^= nums[idx];

        inclusionExclusion(nums, ans, xorSum, idx+1);
    }
public:
    int subsetXORSum(vector<int>& nums) 
    {
        vector<vector<int>> subsets;
        int ans = 0;
        int xorSum = 0;
        inclusionExclusion(nums, ans, xorSum, 0);

        return ans;
    }
};