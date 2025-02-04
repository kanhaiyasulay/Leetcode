class Solution {
public:
    int maxAscendingSum(vector<int>& nums) 
    {
        int sum = 0, maxi = 0;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            maxi = max(maxi, sum);
            if(i == n-1)
            {
                break;
            }
            else if(nums[i] >= nums[i+1])
            {
                sum = 0;
            }
        }

        return maxi;
    }
};