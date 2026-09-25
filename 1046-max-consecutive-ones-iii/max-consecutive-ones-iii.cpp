class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int r = 0, l = 0;
        int maxLen = 0;

        while(r < nums.size())    
        {
            if(nums[r] == 0) k--;

            while(k < 0 && l < r)
            {
                if(nums[l] == 0) k++;
                l++;
            }

            if(k >= 0) maxLen = max(maxLen, r-l+1);
            r++;
        }

        return maxLen;
    }
};