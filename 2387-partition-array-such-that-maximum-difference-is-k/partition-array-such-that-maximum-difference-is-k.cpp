class Solution {
public:
    int partitionArray(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        int cnt = 1, mini = nums[0];
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]-mini > k)
            {
                mini = nums[i];
                cnt++;
            }
        }
        return cnt;
    }
};