class Solution {
public:
    pair<int,int> findMinMax(vector<int>& nums)
    {
        int minEle = nums[0], minIdx = 0;
        int maxEle = nums[0], maxIdx = 0;

        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] < minEle)
            {
                minEle = nums[i];
                minIdx = i;
            }
            if(nums[i] > maxEle)
            {
                maxEle = nums[i];
                maxIdx = i;
            }
        }

        return {minIdx, maxIdx};
    }
    int minimumDeletions(vector<int>& nums) 
    {
        int n = nums.size();
        if(n <= 2) return nums.size();

        pair<int,int> minMax = findMinMax(nums);
        int minIdx = minMax.first, maxIdx = minMax.second;

        int fromFront = max(minIdx, maxIdx)+1;
        int fromBack = n-min(minIdx, maxIdx);

        int front = min(minIdx, maxIdx)+1;
        int back = n-max(minIdx, maxIdx);
        int useBoth = front + back;

        int ans = min(fromFront, min(fromBack, useBoth));

        return ans;

    }
};