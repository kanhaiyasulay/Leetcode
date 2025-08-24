class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int l = 0, r = 0, idx = -1;
        int n = nums.size();
        int maxi = 0;

        while(r < n)
        {
            if(nums[r] == 0)
            {
                if(idx < l)
                {
                    idx = r;
                }
                else
                {
                    maxi = max(maxi, r-l-1);
                    l = idx+1;
                    idx = r;
                }
            }
            r++;
        }

        return max(maxi, r-l-1);
    }
};