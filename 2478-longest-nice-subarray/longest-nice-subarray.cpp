class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) 
    {
        int n = nums.size(), len = 0;
        for(int i=0; i<n; i++)
        {
            int num = 0;
            int j = i;
            for(; j<n; j++)
            {
                if((num&nums[j]) != 0) break;

                num |= nums[j];
                len = max(len, j-i+1);
            }
            if(j == n) len = max(len, j-i);
        }

        return len;
    }
};