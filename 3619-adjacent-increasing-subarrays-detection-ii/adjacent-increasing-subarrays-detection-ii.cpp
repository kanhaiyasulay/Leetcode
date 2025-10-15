class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) 
    {
        int n = nums.size();
        int prevRun = 0, run = 1;
        int maxRun = 1;

        for(int i=1; i<n; i++)
        {
            if(nums[i] > nums[i-1]) 
                run++;
            else
            {
                if(min(prevRun, run)*2 > maxRun)
                    maxRun = min(prevRun, run) * 2;
                
                prevRun = run;
                run = 1;
            }
            maxRun = max(maxRun, run);
        }
        if(min(prevRun, run)*2 > maxRun) 
            maxRun = min(prevRun, run)*2;

        return (maxRun/2 == 0) ? 1 : maxRun/2;
    }
};