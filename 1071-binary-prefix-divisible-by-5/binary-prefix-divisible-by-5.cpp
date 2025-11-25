class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) 
    {
        vector<bool> result;
        int curr = 0;

        for(int i=0; i<nums.size(); i++)
        {
            curr = (curr * 2 + nums[i]) % 5;

            if(curr == 0) result.push_back(true);
            else result.push_back(false);
        }

        return result;
    }
};