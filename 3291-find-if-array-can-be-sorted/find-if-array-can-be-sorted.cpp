class Solution {
public:
    int setBits(int n)
    {
        int cnt = 0;
        while(n != 0)
        {
            if(n&1) cnt++;
            n = n >> 1;
        }
        return cnt;
    }

    bool canSortArray(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> ans;

        while(true)
        {
            int minEle = INT_MAX, minIdx = -1;
            for(int i=0; i<n; i++)
            {
                if(nums[i] == -1) continue;
                if(nums[i] < minEle) 
                {
                    minEle = nums[i];
                    minIdx = i;
                }
            }

            if(minIdx == -1) return true;

            for(int i=minIdx; i>=0; i--)
            {
                if(nums[i] != -1 && setBits(nums[i]) != setBits(nums[minIdx])) 
                    return false;
            }
            
            ans.push_back(nums[minIdx]);

            nums[minIdx] = -1;
        }

        return true;
    }
};