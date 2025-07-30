class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int maxLen = 0, maxi = 0;

        for(auto it:nums ) maxi = max(maxi, it);

        int i=0, j = 0, n = nums.size();

        while(j < n)
        {
            if(nums[i] != nums[j]) 
            {
                if(nums[i] == maxi) maxLen = max(maxLen, j-i);
                i = j;
                continue;
            }
            j++;
        }

        if(nums[i] == maxi) 
        {
            maxLen = max(maxLen, j-i);
        }

        return maxLen == 0 ? 1 : maxLen;
    }
};