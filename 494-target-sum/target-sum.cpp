class Solution {
public:
    int diffEqlToK(vector<int>& nums, int total, int target, int sum, int idx)
    {
        if(idx < 0)
        {
            if (2 * sum == total + target) return 1;
            return 0;
        }

        int inclusion = diffEqlToK(nums, total, target, sum+nums[idx], idx-1);
        int exclusion = diffEqlToK(nums, total, target, sum, idx-1);

        return inclusion + exclusion;
    }
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        return diffEqlToK(nums, total, target, 0, n-1);
    }
};
