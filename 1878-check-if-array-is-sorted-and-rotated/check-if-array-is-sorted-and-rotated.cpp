class Solution {
public:
    bool check(vector<int>& nums) 
    {
        int mini = INT_MAX, idx = nums.size(), prev = INT_MIN;
        for(int i=0; i<nums.size(); i++)    
        {
            if(nums[i] >= prev)
                prev = nums[i];
            else
            {
                prev = nums[i];
                idx = i;
                break;
            }
            mini = min(mini, nums[i]);
        }

        for(int i=idx; i<nums.size(); i++)
        {
            if(nums[i] < prev || nums[i] > mini)
                return false;
        }
        return true;
    }
};