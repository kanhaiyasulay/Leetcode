class Solution {
public:
    int backtrack(vector<int>& nums, int target, int idx)
    {
        if(idx == 0)
        {
            if(target+nums[0] == 0 && target-nums[0] == 0) return 2;
            if(target+nums[0] == 0) return 1;
            if(target-nums[0] == 0) return 1;
            return 0;
        }

        int pos = backtrack(nums, target+nums[idx], idx-1);
        int neg = backtrack(nums, target-nums[idx], idx-1);

        return pos + neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int n = nums.size();
        return backtrack(nums, target, n-1);
    }
};
