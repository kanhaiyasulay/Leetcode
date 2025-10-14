class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int cnt = k*2;
        for(int i=0; i<n; i++)    
        {
            if(n < i+(k*2)) return false;
            cnt = k;
            bool parity = true;

            for(int j=i+1; j<i+k; j++)
            {
                if(nums[j] <= nums[j-1]) 
                {
                    parity = false;
                    break;
                }
            }

            for(int j=i+k+1; j<i+(k*2); j++)
            {
                if(nums[j] <= nums[j-1])
                {
                    parity = false;
                    break;
                }
            }

            if(parity) return true;
        }

        return false;
    }
};