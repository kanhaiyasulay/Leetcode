class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) 
    {
        int space = 0;
        bool first = false;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 1 && space < k && first) return false;
            else if(nums[i] == 1) space = 0;
            else space++;

            if(nums[i] == 1)
            {
                first = true;
                space = 0;
            }
        }

        return true;
    }
};