class Solution {
public:
    int maxAscendingSum(vector<int>& nums) 
    {
        int ans = 0;
        for(int i=0; i<nums.size(); i++)
        {
            int cnt = 0;
            for(int j=i; j<nums.size(); j++)
            {
                if(j == nums.size()-1)
                {
                    cnt += nums[j];
                    continue;
                }
                if(nums[j] < nums[j+1])
                    cnt += nums[j];
                else 
                {
                    cnt += nums[j];
                    break;
                }
            }
            cnt = max(cnt, nums[i]);
            ans = max(ans, cnt);
        }

        return ans;
    }
};