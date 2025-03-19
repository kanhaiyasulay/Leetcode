class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        int n = nums.size(), cnt = 0;
        bool finish = false;
        for(int i=0; i<n; i++)
        {
            bool change = false;
            if(nums[i] == 1) continue;
            for(int j=i; j<i+3; j++)
            {
                if(j >= n) 
                {
                    finish = true;
                    break;
                }
                if(nums[j] == 0)
                {
                    nums[j] = 1;
                    change = true;
                }
                else nums[j] = 0;
            }
            if(change) cnt++;
            if(finish) 
            {
                for(int j=i; j<n; j++) nums[j] = !nums[j];
                break;
            }
        }

        for(auto a:nums ) if(a == 0) return -1;
        return cnt;
    }
};