class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) 
    {
        int run = 1, prevRun = 1; // prevRun = 0 because no previous streak yet
        int n = nums.size();

        for(int i = 1; i < n; i++) 
        {
            if(run >= k*2) return true;
            if(nums[i] > nums[i - 1]) 
                run++;
            else 
            {
                // If both current and previous streaks are long enough
                if(run >= k && prevRun >= k)
                    return true;

                // Update previous run only if current was long enough
                prevRun = (run >= k ? run : 0);
                run = 1;
            }
        }

        // Final check after loop ends
        return ((run >= k && prevRun >= k) || run >= k*2);
    }
};
