class Solution {
public:
    int maximumCount(vector<int>& nums) 
    {
        int cntPos = 0, cntNeg = 0, maxPos = 0, maxNeg = 0, n = nums.size();

        for(int i=0; i<n; i++)
        {
            if(nums[i] > 0) 
            {
                maxNeg = max(maxNeg, cntNeg);
                cntNeg = 0;
                cntPos++;
            }
            else if(nums[i] < 0)
            {
                maxPos = max(maxPos, cntPos);
                cntPos = 0;
                cntNeg++;
            }
            else 
            {
                maxNeg = max(maxNeg, cntNeg);
                maxPos = max(maxPos, cntPos);
                cntNeg = 0;
                cntPos = 0;
            }
        }
        maxPos = max(maxPos, cntPos);
        maxNeg = max(maxNeg, cntNeg);

        return max(maxNeg, maxPos);
    }
};