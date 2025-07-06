class Solution {
public:
    int backtrack(vector<int>& nums, int target, int idx)
    {
        if(idx == 0)
        {
            if(target == 0 && target == nums[0]) return 2;
            if(target == 0) return 1;
            if(target == nums[0]) return 1;
            return 0;
        }
        
        int exclusion = backtrack(nums, target, idx-1);
        int inclusion = 0;
        if(target >= nums[idx])
            inclusion = backtrack(nums, target-nums[idx], idx-1);
        
        return (inclusion + exclusion);
    }
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int newTarget = (total+target)/2;
        // VV IMP
        if (total < abs(target) || (target + total) % 2 != 0) return 0;

        return backtrack(nums, newTarget, nums.size()-1);
    }
};