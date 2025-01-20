class Solution {
public:
    int minStartValue(vector<int>& nums) 
    {
        int mini = 1;
        int sum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            mini = min(mini, sum);
        }

        if(mini > 0) return mini;
        return (mini * -1) + 1;
    }
};