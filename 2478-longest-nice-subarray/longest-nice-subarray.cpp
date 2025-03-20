class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) 
    {
        int n = nums.size(), len = 0, num = 0;

        for(int s=0, e=0; e<n; e++)
        {
            while((num & nums[e]) != 0)
            {
                num ^= nums[s];
                s++;
            }
            num |= nums[e];

            len = max(len, e-s+1);
        }

        return len;
    }
};