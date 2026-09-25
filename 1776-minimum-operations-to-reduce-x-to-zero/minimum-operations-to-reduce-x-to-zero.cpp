class Solution {
public:
    int sw(vector<int>& nums, int target)
    {
        int r = 0, l = 0;
        int maxLen = 0;

        while(r < nums.size())
        {
            target -= nums[r];
            if(target < 0 && l <= r)
            {
                while(target < 0 && l <= r) target += nums[l++];
            }
            if(target == 0)
                maxLen = max(maxLen, r-l+1);
            
                r++;
        }

        int ans = nums.size()-maxLen;
        return maxLen == 0 ? -1 : ans;
    }
    int minOperations(vector<int>& nums, int x) 
    {
        int sum = 0;
        for(auto it:nums ) sum += it;

        if(sum == x) return nums.size();

        int target = sum - x;
        return sw(nums, target);    
    }
};