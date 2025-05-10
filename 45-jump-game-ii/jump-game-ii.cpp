class Solution {
public:
    int jump(vector<int>& nums) 
    {
        if (nums.size() <= 1) return 0;

        int stepCount = 0;
        int maxReachable = nums[0];
        int currentLimit = nums[0];

        for (int pos = 1; pos < nums.size(); ++pos) {
            if (pos == nums.size() - 1) {
                return stepCount + 1;
            }

            maxReachable = std::max(maxReachable, pos + nums[pos]);

            if (pos == currentLimit) {
                ++stepCount;
                currentLimit = maxReachable;
            }
        }

        return stepCount;
    }
};