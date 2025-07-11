class Solution {
public:
    int maxSumWithWindowSizeK(vector<int>& nums, int k)
    {
        int l = 0, r = 0, n = nums.size();
        int sum = 0, maxSum = 0;

        while(r < n)
        {
            sum += nums[r];
            if(r-l+1 > k+1)
            {
                sum -= nums[l];
                l++;
            }
            r++;
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) 
    {
        int n = startTime.size();
        vector<int> sW;
        sW.push_back(startTime[0]);
        for(int i=0; i<n-1; i++)
        {
            sW.push_back(startTime[i+1]-endTime[i]);
        }
        sW.push_back(eventTime-endTime.back());

        return maxSumWithWindowSizeK(sW, k);
    }
};