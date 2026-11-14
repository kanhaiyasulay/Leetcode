class Solution {
public:
    int backtrack(vector<int>& nums, int target, int sum, int idx)
    {
        if(idx >= nums.size() && sum != target) return 0;
        if(idx == nums.size() && sum == target) return 1;
        
        int add = backtrack(nums, target, sum+nums[idx], idx+1);
        int subtract = backtrack(nums, target, sum-nums[idx], idx+1);

        return add + subtract;
    }
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        return backtrack(nums, target, 0, 0);
    }
};