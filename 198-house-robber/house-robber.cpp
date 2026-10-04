class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();

        int prev = nums[0];
        int prev2 = 0;
        int ans = 0;
        for(int i=1; i<n; i++)
        {
            int inclusion = nums[i] + prev2; 
            int exclusion = prev;

            int curr = max(inclusion, exclusion);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};